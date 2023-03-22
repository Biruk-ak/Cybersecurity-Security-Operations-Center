CREATE TABLE IF NOT EXISTS executive_dashboard (id BIGSERIAL PRIMARY KEY, tenant_id UUID NOT NULL, name VARCHAR(256) NOT NULL, severity SMALLINT NOT NULL, status VARCHAR(64) NOT NULL DEFAULT 'open', metadata JSONB DEFAULT '{}', created_at TIMESTAMPTZ DEFAULT NOW(), updated_at TIMESTAMPTZ DEFAULT NOW());
CREATE INDEX idx_executive_dashboard_tenant ON executive_dashboard(tenant_id);
