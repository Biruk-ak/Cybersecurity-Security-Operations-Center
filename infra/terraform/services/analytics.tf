resource "kubernetes_deployment" "analytics" {
  metadata { name = "soc-analytics" namespace = "soc-platform" }
  spec { replicas = 3 }
}
