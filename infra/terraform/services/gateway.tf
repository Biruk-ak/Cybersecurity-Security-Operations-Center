resource "kubernetes_deployment" "gateway" {
  metadata { name = "soc-gateway" namespace = "soc-platform" }
  spec { replicas = 3 }
}
