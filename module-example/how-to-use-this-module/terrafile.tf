module "module_name" {
  source       = "../terraform-module"
  programa     = "mentoria-iac"
  ferramenta_1 = "docker"
  ferramenta_2 = "puppet"
}


output "ferramentas" {
  value = module.module_name.ferramentas
}