resource "kubernetes_deployment" "soar_engine" {
  metadata { name = "soc-soar-engine" namespace = "soc-platform" }
  spec { replicas = 3 }
}
