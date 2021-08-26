resource "local_file" "ferramenta-1" {
  content  = "${var.programa} - Estudos ${var.ferramenta_1}"
  filename = "${path.root}/${var.ferramenta_1}.txt"
}

resource "local_file" "ferramenta-2" {
  content  = "${var.programa} - Estudos ${var.ferramenta_2}"
  filename = "${path.root}/${var.ferramenta_2}.txt"
}
