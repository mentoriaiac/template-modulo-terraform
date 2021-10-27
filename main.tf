data "hashicups_coffees" "all" {}

locals {
  coffee_name_id_map = { for coffee in data.hashicups_coffees.all.coffees : coffee.name => coffee.id }
}

resource "hashicups_order" "order" {
  dynamic "items" {
    for_each = var.order
    content {
      coffee {
        id = local.coffee_name_id_map[items.key]
      }
      quantity = items.value
    }
  }
}

