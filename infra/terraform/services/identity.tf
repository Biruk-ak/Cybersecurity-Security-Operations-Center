resource "kubernetes_deployment" "identity" {
  metadata { name = "soc-identity" namespace = "soc-platform" }
  spec { replicas = 3 }
}
