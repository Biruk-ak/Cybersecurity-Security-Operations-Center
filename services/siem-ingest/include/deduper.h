#ifndef SOC_SIEM_INGEST_DEDUPER_H
#define SOC_SIEM_INGEST_DEDUPER_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_DEDUPER_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_deduper_rec_t;

typedef struct { soc_deduper_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_deduper_db_t;

soc_deduper_db_t *soc_deduper_db_create(size_t n);
void soc_deduper_db_destroy(soc_deduper_db_t *db);
int soc_deduper_db_upsert(soc_deduper_db_t *db, const soc_deduper_rec_t *rec);
int soc_deduper_db_remove(soc_deduper_db_t *db, uint64_t id);
int soc_deduper_db_find(const soc_deduper_db_t *db, uint64_t id, soc_deduper_rec_t *out);
size_t soc_deduper_db_scan(const soc_deduper_db_t *db, uint32_t min_sev, soc_deduper_rec_t *out, size_t max);
uint64_t soc_deduper_hash(const void *p, size_t n);
int soc_deduper_validate(const soc_deduper_rec_t *rec);
int soc_deduper_to_json(const soc_deduper_rec_t *rec, char *buf, size_t len);
void soc_deduper_metrics(const soc_deduper_db_t *db, char *buf, size_t len);
int soc_deduper_correlate(soc_deduper_db_t *db, const soc_deduper_rec_t *seed, soc_deduper_rec_t *out, size_t max);
int soc_deduper_fn_000(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_001(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_002(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_003(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_004(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_005(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_006(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_007(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_008(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_009(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_010(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_011(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_012(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_013(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_014(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_015(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_016(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_017(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_018(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_019(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_020(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_021(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_022(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_023(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_024(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_025(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_026(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_027(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_028(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_029(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_030(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_031(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_032(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_033(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_034(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_035(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_036(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_037(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_038(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_039(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_040(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_041(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_042(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_043(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_044(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_045(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_046(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_047(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_048(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_049(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_050(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_051(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_052(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_053(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_054(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_055(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_056(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_057(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_058(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_059(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_060(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_061(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_062(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_063(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_064(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_065(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_066(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_067(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_068(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_069(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_070(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_deduper_fn_071(soc_deduper_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SIEM_INGEST_DEDUPER_H */
