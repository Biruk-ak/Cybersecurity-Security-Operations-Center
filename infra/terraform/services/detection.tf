resource "kubernetes_deployment" "detection" {
  metadata { name = "soc-detection" namespace = "soc-platform" }
  spec { replicas = 3 }
}
