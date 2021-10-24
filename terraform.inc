MAKEFLAGS  	      += --silent
SHELL      	      = /bin/bash

ifndef MODULE_DIR
MODULE_DIR := $(shell dirname $$PWD)
endif

ifndef TARGET_FOLDER
	TARGET_FOLDER := ""
endif

ifndef TARGET_ENV
	ERROR := $(error TARGET_ENV file not provided, please create it)
endif
BUCKET_NAME := $(shell awk -F'=' '/BUCKET_NAME/{print $$2}' ${TARGET_ENV})

ifndef TERRAFORM_VERSION
	TERRAFORM_VERSION := 1.0.0
endif

ifndef TFPLAN
	TFPLAN := tfplan
endif

# HELP
# This will output the help for each task
# thanks to https://marmelab.com/blog/2016/02/29/auto-documented-makefile.html
.PHONY: help

help: ## This help
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?## / {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)

terraform-tfsec: ## Execute tfsec in terraform files
	echo "STEP: terraform-tfsec - Execute tfsec in terraform files"
	docker run --rm -v $(MODULE_DIR):/app -w /app/${TARGET_FOLDER} tfsec/tfsec . --no-color

terraform-validate: ## Execute terraform validate in terraform files
	echo "STEP: terraform-validate - Execute terraform validate in terraform files"
	docker run --rm -v $(MODULE_DIR):/app -w /app/${TARGET_FOLDER} --env-file $(TARGET_ENV) hashicorp/terraform:$(TERRAFORM_VERSION) validate

terraform-clean: ## Remove terraform files untracked in git
	echo "STEP: terraform-clean - Remove terraform files untracked in git"
	rm -rf ./${TARGET_FOLDER}/.terraform/ && \
	rm -rf ./${TARGET_FOLDER}/.terraform.* && \
	rm -f ./${TARGET_FOLDER}/.terraform.lock.hcl && \
	rm -f ${TFPLAN}

terraform-fmt: ## Execute terraform fmt in terraform files
	echo "STEP: terraform-fmt - Execute terraform fmt in terraform files"
	docker run --rm -v $(MODULE_DIR):/app -w /app/${TARGET_FOLDER} hashicorp/terraform:$(TERRAFORM_VERSION) fmt -recursive

terraform-generate-backend-gcs:  ## Generate file backend.tf on Google Cloud Storage
	echo "STEP: terraform-generate-backend - Generate file backend.tf"
	echo -e "terraform {\nbackend \"gcs\" { bucket  = \"$(BUCKET_NAME)\" }\n}" > ./${TARGET_FOLDER}/backend.tf && \
	terraform fmt

terraform-init: ## Execute terraform init in terraform files
	echo "STEP: terraform-init - Execute terraform init in terraform files"
	docker run --rm -v $(MODULE_DIR):/app -w /app/${TARGET_FOLDER} --env-file $(TARGET_ENV) hashicorp/terraform:$(TERRAFORM_VERSION) init

terraform-plan: terraform-validate  ## Execute terraform validate, tfsec and plan in terraform files
	echo "STEP: terraform-plan - Execute terraform validate, tfsec and plan in terraform files"
	docker run --rm -v $(MODULE_DIR):/app -w /app/${TARGET_FOLDER} --env-file $(TARGET_ENV) hashicorp/terraform:$(TERRAFORM_VERSION) plan -out ${TFPLAN}

terraform-apply: ## Execute terraform apply in terraform files
	echo "STEP: terraform-apply - Execute terraform apply in terraform files"
	docker run --rm -v $(MODULE_DIR):/app -w /app/${TARGET_FOLDER} --env-file $(TARGET_ENV) hashicorp/terraform:$(TERRAFORM_VERSION) apply -auto-approve ${TFPLAN}
	
terraform-destroy: ## Execute terraform destroy in terraform files
	echo "STEP: terraform-destroy - Execute terraform destroy in terraform files"
	docker run --rm -v $(MODULE_DIR):/app -w /app/${TARGET_FOLDER} --env-file $(TARGET_ENV) hashicorp/terraform:$(TERRAFORM_VERSION) destroy -auto-approve

init: terraform-init ## alias for terraform init
fmt: terraform-fmt ## alias for terraform fmt
plan: fmt terraform-init terraform-plan ## Execute terraform fmt, init, plan in terraform files
apply: terraform-apply ## alias for terraform apply
destroy: terraform-destroy ## alias for terraform destroy
clean: terraform-clean ## alias for terraform clean
test: plan terraform-apply terraform-destroy ## Execute terraform plan, apply, destroy in terraform files
validate: terraform-validate ## alias for terraform validate