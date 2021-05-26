module "estudos" {
  source       = "../terraform-module"
  programa     = "mentoria-iac"
  ferramenta_1 = "docker"
  ferramenta_2 = "puppet"
}


output "ferramentas" {
  value = module.estudos.ferramentas
}