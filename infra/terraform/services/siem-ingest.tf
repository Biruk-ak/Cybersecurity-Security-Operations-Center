resource "kubernetes_deployment" "siem_ingest" {
  metadata { name = "soc-siem-ingest" namespace = "soc-platform" }
  spec { replicas = 3 }
}
