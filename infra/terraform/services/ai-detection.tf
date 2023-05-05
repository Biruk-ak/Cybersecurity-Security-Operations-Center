resource "kubernetes_deployment" "ai_detection" {
  metadata { name = "soc-ai-detection" namespace = "soc-platform" }
  spec { replicas = 3 }
}
