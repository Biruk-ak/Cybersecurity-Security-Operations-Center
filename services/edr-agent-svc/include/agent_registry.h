#ifndef SOC_EDR_AGENT_SVC_AGENT_REGISTRY_H
#define SOC_EDR_AGENT_SVC_AGENT_REGISTRY_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_AGENT_REGISTRY_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_agent_registry_rec_t;

typedef struct { soc_agent_registry_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_agent_registry_db_t;

soc_agent_registry_db_t *soc_agent_registry_db_create(size_t n);
void soc_agent_registry_db_destroy(soc_agent_registry_db_t *db);
int soc_agent_registry_db_upsert(soc_agent_registry_db_t *db, const soc_agent_registry_rec_t *rec);
int soc_agent_registry_db_remove(soc_agent_registry_db_t *db, uint64_t id);
int soc_agent_registry_db_find(const soc_agent_registry_db_t *db, uint64_t id, soc_agent_registry_rec_t *out);
size_t soc_agent_registry_db_scan(const soc_agent_registry_db_t *db, uint32_t min_sev, soc_agent_registry_rec_t *out, size_t max);
uint64_t soc_agent_registry_hash(const void *p, size_t n);
int soc_agent_registry_validate(const soc_agent_registry_rec_t *rec);
int soc_agent_registry_to_json(const soc_agent_registry_rec_t *rec, char *buf, size_t len);
void soc_agent_registry_metrics(const soc_agent_registry_db_t *db, char *buf, size_t len);
int soc_agent_registry_correlate(soc_agent_registry_db_t *db, const soc_agent_registry_rec_t *seed, soc_agent_registry_rec_t *out, size_t max);
int soc_agent_registry_fn_000(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_001(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_002(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_003(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_004(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_005(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_006(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_007(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_008(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_009(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_010(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_011(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_012(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_013(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_014(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_015(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_016(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_017(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_018(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_019(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_020(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_021(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_022(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_023(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_024(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_025(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_026(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_027(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_028(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_029(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_030(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_031(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_032(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_033(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_034(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_035(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_036(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_037(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_038(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_039(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_040(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_041(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_042(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_043(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_044(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_045(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_046(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_047(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_048(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_049(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_050(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_051(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_052(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_053(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_054(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_055(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_056(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_057(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_058(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_059(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_060(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_061(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_062(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_063(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_064(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_065(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_066(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_067(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_068(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_069(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_070(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_agent_registry_fn_071(soc_agent_registry_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_EDR_AGENT_SVC_AGENT_REGISTRY_H */
