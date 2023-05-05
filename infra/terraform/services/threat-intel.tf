resource "kubernetes_deployment" "threat_intel" {
  metadata { name = "soc-threat-intel" namespace = "soc-platform" }
  spec { replicas = 3 }
}
