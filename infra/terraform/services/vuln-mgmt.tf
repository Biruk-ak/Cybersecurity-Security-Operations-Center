resource "kubernetes_deployment" "vuln_mgmt" {
  metadata { name = "soc-vuln-mgmt" namespace = "soc-platform" }
  spec { replicas = 3 }
}
