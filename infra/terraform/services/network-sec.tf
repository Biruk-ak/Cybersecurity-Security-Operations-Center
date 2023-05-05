resource "kubernetes_deployment" "network_sec" {
  metadata { name = "soc-network-sec" namespace = "soc-platform" }
  spec { replicas = 3 }
}
