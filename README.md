## Requirements

| Name | Version |
|------|---------|
| <a name="requirement_terraform"></a> [terraform](#requirement\_terraform) | >= 1.0.0 |
| <a name="requirement_hashicups"></a> [hashicups](#requirement\_hashicups) | ~> 0.3.1 |

## Providers

| Name | Version |
|------|---------|
| <a name="provider_hashicups"></a> [hashicups](#provider\_hashicups) | 0.3.1 |

## Modules

No modules.

## Resources

| Name | Type |
|------|------|
| [hashicups_order.order](https://registry.terraform.io/providers/hashicorp/hashicups/latest/docs/resources/order) | resource |
| [hashicups_coffees.all](https://registry.terraform.io/providers/hashicorp/hashicups/latest/docs/data-sources/coffees) | data source |

## Inputs

| Name | Description | Type | Default | Required |
|------|-------------|------|---------|:--------:|
| <a name="input_order"></a> [order](#input\_order) | Mapa de cafe e quantidade | `map(number)` | n/a | yes |

## Outputs

| Name | Description |
|------|-------------|
| <a name="output_order_id"></a> [order\_id](#output\_order\_id) | n/a |

## Como usar esse módulo
[Acesse o passo-a-passo](how-to-use-this-module/README.md)