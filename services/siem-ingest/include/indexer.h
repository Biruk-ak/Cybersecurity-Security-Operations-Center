#ifndef SOC_SIEM_INGEST_INDEXER_H
#define SOC_SIEM_INGEST_INDEXER_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_INDEXER_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_indexer_rec_t;

typedef struct { soc_indexer_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_indexer_db_t;

soc_indexer_db_t *soc_indexer_db_create(size_t n);
void soc_indexer_db_destroy(soc_indexer_db_t *db);
int soc_indexer_db_upsert(soc_indexer_db_t *db, const soc_indexer_rec_t *rec);
int soc_indexer_db_remove(soc_indexer_db_t *db, uint64_t id);
int soc_indexer_db_find(const soc_indexer_db_t *db, uint64_t id, soc_indexer_rec_t *out);
size_t soc_indexer_db_scan(const soc_indexer_db_t *db, uint32_t min_sev, soc_indexer_rec_t *out, size_t max);
uint64_t soc_indexer_hash(const void *p, size_t n);
int soc_indexer_validate(const soc_indexer_rec_t *rec);
int soc_indexer_to_json(const soc_indexer_rec_t *rec, char *buf, size_t len);
void soc_indexer_metrics(const soc_indexer_db_t *db, char *buf, size_t len);
int soc_indexer_correlate(soc_indexer_db_t *db, const soc_indexer_rec_t *seed, soc_indexer_rec_t *out, size_t max);
int soc_indexer_fn_000(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_001(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_002(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_003(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_004(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_005(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_006(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_007(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_008(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_009(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_010(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_011(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_012(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_013(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_014(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_015(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_016(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_017(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_018(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_019(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_020(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_021(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_022(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_023(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_024(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_025(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_026(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_027(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_028(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_029(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_030(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_031(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_032(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_033(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_034(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_035(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_036(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_037(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_038(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_039(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_040(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_041(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_042(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_043(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_044(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_045(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_046(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_047(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_048(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_049(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_050(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_051(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_052(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_053(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_054(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_055(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_056(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_057(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_058(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_059(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_060(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_061(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_062(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_063(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_064(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_065(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_066(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_067(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_068(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_069(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_070(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_indexer_fn_071(soc_indexer_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SIEM_INGEST_INDEXER_H */
