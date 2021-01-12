#ifndef SOC_SIEM_INGEST_ENRICHER_H
#define SOC_SIEM_INGEST_ENRICHER_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_ENRICHER_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_enricher_rec_t;

typedef struct { soc_enricher_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_enricher_db_t;

soc_enricher_db_t *soc_enricher_db_create(size_t n);
void soc_enricher_db_destroy(soc_enricher_db_t *db);
int soc_enricher_db_upsert(soc_enricher_db_t *db, const soc_enricher_rec_t *rec);
int soc_enricher_db_remove(soc_enricher_db_t *db, uint64_t id);
int soc_enricher_db_find(const soc_enricher_db_t *db, uint64_t id, soc_enricher_rec_t *out);
size_t soc_enricher_db_scan(const soc_enricher_db_t *db, uint32_t min_sev, soc_enricher_rec_t *out, size_t max);
uint64_t soc_enricher_hash(const void *p, size_t n);
int soc_enricher_validate(const soc_enricher_rec_t *rec);
int soc_enricher_to_json(const soc_enricher_rec_t *rec, char *buf, size_t len);
void soc_enricher_metrics(const soc_enricher_db_t *db, char *buf, size_t len);
int soc_enricher_correlate(soc_enricher_db_t *db, const soc_enricher_rec_t *seed, soc_enricher_rec_t *out, size_t max);
int soc_enricher_fn_000(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_001(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_002(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_003(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_004(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_005(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_006(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_007(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_008(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_009(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_010(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_011(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_012(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_013(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_014(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_015(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_016(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_017(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_018(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_019(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_020(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_021(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_022(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_023(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_024(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_025(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_026(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_027(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_028(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_029(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_030(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_031(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_032(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_033(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_034(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_035(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_036(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_037(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_038(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_039(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_040(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_041(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_042(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_043(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_044(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_045(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_046(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_047(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_048(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_049(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_050(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_051(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_052(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_053(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_054(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_055(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_056(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_057(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_058(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_059(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_060(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_061(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_062(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_063(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_064(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_065(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_066(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_067(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_068(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_069(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_070(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_enricher_fn_071(soc_enricher_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SIEM_INGEST_ENRICHER_H */
