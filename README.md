##  Template Modulo Terraform
Este repositorio deve conter a estrutura básica para a criação de uma modulo do [terraform](https://www.terraform.io/). 

 $`` module-example/``
 
 |--- main.tf  
 |--- variable.tf  
 |--- outputs.tf  
 |--- version.tf


 Esses são os nomes de arquivos recomendados para um modulo mínimo, mesmo se estiverem vazios. 
 
 ``main.tf`` deve ser o ponto de entrada principal.
 Para um modulo simples, pode ser aqui que todos os recursos que são criados. Para uma modulo complexo pode ser divido em varios arquivos.
 
 ``variables.tf e outputs.tf`` deve conter as declarações das variaves e as saidas respectivamente.
 
 ``versions.tf`` deve contem as versões dos recursos/provedores

## Requirements

| Name | Version |
|------|---------|
| Terraform | >= 0.13.0 |

## Providers
  
| Name | Version |
|------|---------|
| local | n/a |

## Resources

| Name | Type |
|------|------|
| local_file | resource |
| local_file | data source |

## Inputs

| Name | Description | Type | Default | Required |
|------|-------------|------|---------|:--------:|
|ferramenta_1 | exemplo de variavel | `string` | `"terraform"` | no |
|ferramenta_2 | exemplo de variavel | `string` | `"ansible"` | no |
|programa | exemplo de variavel | `string` | `"mentoria-iac"` | no |

## Outputs
 
| Name | Description |
|------|-------------|
|ferramentas | exemplo de saida |

## Testar localmente

Aqui você descreve como a pessoa que utilizar esse módulo pode testar localmente. Coloque todos os detalhes necessários para executar localmente.

  
