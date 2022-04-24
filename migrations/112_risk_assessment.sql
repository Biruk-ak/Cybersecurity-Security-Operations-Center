CREATE TABLE IF NOT EXISTS risk_assessment (id BIGSERIAL PRIMARY KEY, tenant_id UUID NOT NULL, name VARCHAR(256) NOT NULL, severity SMALLINT NOT NULL, status VARCHAR(64) NOT NULL DEFAULT 'open', metadata JSONB DEFAULT '{}', created_at TIMESTAMPTZ DEFAULT NOW(), updated_at TIMESTAMPTZ DEFAULT NOW());
CREATE INDEX idx_risk_assessment_tenant ON risk_assessment(tenant_id);
