#ifndef SOC_SIEM_INGEST_NORMALIZER_H
#define SOC_SIEM_INGEST_NORMALIZER_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_NORMALIZER_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_normalizer_rec_t;

typedef struct { soc_normalizer_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_normalizer_db_t;

soc_normalizer_db_t *soc_normalizer_db_create(size_t n);
void soc_normalizer_db_destroy(soc_normalizer_db_t *db);
int soc_normalizer_db_upsert(soc_normalizer_db_t *db, const soc_normalizer_rec_t *rec);
int soc_normalizer_db_remove(soc_normalizer_db_t *db, uint64_t id);
int soc_normalizer_db_find(const soc_normalizer_db_t *db, uint64_t id, soc_normalizer_rec_t *out);
size_t soc_normalizer_db_scan(const soc_normalizer_db_t *db, uint32_t min_sev, soc_normalizer_rec_t *out, size_t max);
uint64_t soc_normalizer_hash(const void *p, size_t n);
int soc_normalizer_validate(const soc_normalizer_rec_t *rec);
int soc_normalizer_to_json(const soc_normalizer_rec_t *rec, char *buf, size_t len);
void soc_normalizer_metrics(const soc_normalizer_db_t *db, char *buf, size_t len);
int soc_normalizer_correlate(soc_normalizer_db_t *db, const soc_normalizer_rec_t *seed, soc_normalizer_rec_t *out, size_t max);
int soc_normalizer_fn_000(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_001(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_002(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_003(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_004(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_005(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_006(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_007(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_008(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_009(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_010(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_011(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_012(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_013(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_014(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_015(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_016(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_017(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_018(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_019(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_020(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_021(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_022(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_023(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_024(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_025(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_026(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_027(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_028(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_029(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_030(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_031(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_032(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_033(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_034(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_035(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_036(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_037(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_038(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_039(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_040(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_041(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_042(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_043(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_044(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_045(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_046(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_047(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_048(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_049(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_050(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_051(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_052(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_053(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_054(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_055(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_056(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_057(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_058(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_059(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_060(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_061(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_062(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_063(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_064(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_065(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_066(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_067(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_068(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_069(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_070(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_normalizer_fn_071(soc_normalizer_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SIEM_INGEST_NORMALIZER_H */
