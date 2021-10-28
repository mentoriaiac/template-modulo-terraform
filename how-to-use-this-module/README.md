# Template de módulo Terraform

## Dependências

Para realizar os testes localmente é necessário:

| Ferramentas | Versão | Instalação |
| ----------- | ------ | ---------- |
| Terraform   | >= 1.0.0 | [Acesse](https://learn.hashicorp.com/tutorials/terraform/install-cli) |
| Docker      | >= 20.10 | [Acesse](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-20-04-pt) |
| Shipyard.run | >= 0.3.36 | [Acesse](https://shipyard.run/docs/install) |
| Git |  >= 2.30.2 | [Acesse](https://git-scm.com/downloads) |

# Criando o ambiente para a API do Hashicups

Instalação do Shipyard.run

```

curl https://shipyard.run/install | bash

```

Clone o repositório e acesse a pasta blueprint

```

git clone https://github.com/hashicorp-demoapp/product-api-go
cd product-api-go/blueprint/

```

Inicie a aplicação executando o comando a baixo

```

shipyard run

```

Saída Esperada

```bash

The API can be accessed at
[http://localhost:19090/coffees](http://localhost:19090/coffees)

```

Crie um usuário para a aplicação

```

curl -X POST localhost:19090/signup -d '{"username":"mentoriaiac", "password":"2021@mentoria"}'

```

# Utilizando o módulo

### Primeiro Passo:

Acesse o repósitorio do módulo :

<pre>

├── product-api-go
│   ├── blueprint
│   ├── client
│   ├── config
│   ├── data
│   │   └── model
│   ├── database
│   ├── docker_compose
│   ├── functional_tests
│   │   └── features
│   ├── handlers
│   └── telemetry
<b>└── template-modulo-terraform </b>
    └── how-to-use-this-module

</pre>

Depois acesse a pasta how-to-use-this-module

```

cd ./how-to-use-this-module/

```

Inicialize o Terraform

```

terraform init

```

### Segundo Passo:

Personalize o `terrafile.tf`:

```
 order = {
    Terraspresso = 4,
    Nomadicano = 10,
    "Vagrante espresso" = 4,
    Packer Spiced Latte = 6,
    Vaulatte = 8,
    Connectaccino = 2
    }  

```

Tente criar o primeiro plan:
```

terraform plan

```

Obs.: Caso retorne erro 401, verifique o usuário e a senha.

### Terceiro Passo:

Aplique suas mudanças:

```

terraform apply

```