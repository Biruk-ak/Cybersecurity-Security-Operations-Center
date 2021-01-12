#ifndef SOC_SIEM_INGEST_PIPELINE_H
#define SOC_SIEM_INGEST_PIPELINE_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_PIPELINE_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_pipeline_rec_t;

typedef struct { soc_pipeline_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_pipeline_db_t;

soc_pipeline_db_t *soc_pipeline_db_create(size_t n);
void soc_pipeline_db_destroy(soc_pipeline_db_t *db);
int soc_pipeline_db_upsert(soc_pipeline_db_t *db, const soc_pipeline_rec_t *rec);
int soc_pipeline_db_remove(soc_pipeline_db_t *db, uint64_t id);
int soc_pipeline_db_find(const soc_pipeline_db_t *db, uint64_t id, soc_pipeline_rec_t *out);
size_t soc_pipeline_db_scan(const soc_pipeline_db_t *db, uint32_t min_sev, soc_pipeline_rec_t *out, size_t max);
uint64_t soc_pipeline_hash(const void *p, size_t n);
int soc_pipeline_validate(const soc_pipeline_rec_t *rec);
int soc_pipeline_to_json(const soc_pipeline_rec_t *rec, char *buf, size_t len);
void soc_pipeline_metrics(const soc_pipeline_db_t *db, char *buf, size_t len);
int soc_pipeline_correlate(soc_pipeline_db_t *db, const soc_pipeline_rec_t *seed, soc_pipeline_rec_t *out, size_t max);
int soc_pipeline_fn_000(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_001(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_002(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_003(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_004(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_005(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_006(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_007(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_008(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_009(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_010(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_011(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_012(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_013(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_014(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_015(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_016(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_017(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_018(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_019(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_020(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_021(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_022(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_023(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_024(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_025(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_026(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_027(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_028(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_029(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_030(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_031(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_032(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_033(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_034(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_035(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_036(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_037(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_038(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_039(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_040(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_041(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_042(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_043(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_044(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_045(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_046(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_047(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_048(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_049(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_050(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_051(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_052(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_053(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_054(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_055(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_056(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_057(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_058(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_059(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_060(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_061(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_062(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_063(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_064(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_065(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_066(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_067(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_068(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_069(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_070(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_pipeline_fn_071(soc_pipeline_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SIEM_INGEST_PIPELINE_H */
