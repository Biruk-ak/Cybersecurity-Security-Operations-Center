#ifndef SOC_EDR_AGENT_SVC_TELEMETRY_H
#define SOC_EDR_AGENT_SVC_TELEMETRY_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_TELEMETRY_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_telemetry_rec_t;

typedef struct { soc_telemetry_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_telemetry_db_t;

soc_telemetry_db_t *soc_telemetry_db_create(size_t n);
void soc_telemetry_db_destroy(soc_telemetry_db_t *db);
int soc_telemetry_db_upsert(soc_telemetry_db_t *db, const soc_telemetry_rec_t *rec);
int soc_telemetry_db_remove(soc_telemetry_db_t *db, uint64_t id);
int soc_telemetry_db_find(const soc_telemetry_db_t *db, uint64_t id, soc_telemetry_rec_t *out);
size_t soc_telemetry_db_scan(const soc_telemetry_db_t *db, uint32_t min_sev, soc_telemetry_rec_t *out, size_t max);
uint64_t soc_telemetry_hash(const void *p, size_t n);
int soc_telemetry_validate(const soc_telemetry_rec_t *rec);
int soc_telemetry_to_json(const soc_telemetry_rec_t *rec, char *buf, size_t len);
void soc_telemetry_metrics(const soc_telemetry_db_t *db, char *buf, size_t len);
int soc_telemetry_correlate(soc_telemetry_db_t *db, const soc_telemetry_rec_t *seed, soc_telemetry_rec_t *out, size_t max);
int soc_telemetry_fn_000(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_001(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_002(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_003(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_004(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_005(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_006(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_007(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_008(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_009(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_010(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_011(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_012(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_013(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_014(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_015(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_016(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_017(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_018(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_019(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_020(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_021(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_022(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_023(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_024(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_025(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_026(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_027(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_028(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_029(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_030(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_031(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_032(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_033(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_034(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_035(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_036(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_037(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_038(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_039(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_040(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_041(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_042(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_043(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_044(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_045(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_046(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_047(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_048(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_049(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_050(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_051(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_052(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_053(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_054(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_055(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_056(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_057(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_058(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_059(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_060(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_061(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_062(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_063(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_064(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_065(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_066(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_067(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_068(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_069(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_070(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_telemetry_fn_071(soc_telemetry_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_EDR_AGENT_SVC_TELEMETRY_H */
