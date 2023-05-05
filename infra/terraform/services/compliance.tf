resource "kubernetes_deployment" "compliance" {
  metadata { name = "soc-compliance" namespace = "soc-platform" }
  spec { replicas = 3 }
}
