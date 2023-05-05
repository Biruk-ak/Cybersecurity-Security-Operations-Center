resource "kubernetes_deployment" "edr_agent_svc" {
  metadata { name = "soc-edr-agent-svc" namespace = "soc-platform" }
  spec { replicas = 3 }
}
