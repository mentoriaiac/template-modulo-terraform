provider "hashicups" {
  username = "mentoriaiac"
  password = "2021@mentoria"
}

module "hashicups_order" {
  source       = "../"
  order = {
    Terraspresso = 4,
    Nomadicano = 10
    }  
}

output "hashicups_order_id" {
  value = module.hashicups_order.order_id
}
