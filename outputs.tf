data "local_file" "ferramenta_1" {
  filename   = "${path.root}/${var.ferramenta_1}.txt"
  depends_on = [local_file.ferramenta-1]
}

data "local_file" "ferramenta_2" {
  filename   = "${path.root}/${var.ferramenta_2}.txt"
  depends_on = [local_file.ferramenta-2]
}

output "ferramentas" {
  description = "exemplo de saidas"
  value = [
    data.local_file.ferramenta_1.content,
    data.local_file.ferramenta_2.content,

  ]
}

