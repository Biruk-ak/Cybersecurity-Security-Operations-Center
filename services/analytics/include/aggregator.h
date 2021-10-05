#ifndef SOC_ANALYTICS_AGGREGATOR_H
#define SOC_ANALYTICS_AGGREGATOR_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_AGGREGATOR_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_aggregator_rec_t;

typedef struct { soc_aggregator_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_aggregator_db_t;

soc_aggregator_db_t *soc_aggregator_db_create(size_t n);
void soc_aggregator_db_destroy(soc_aggregator_db_t *db);
int soc_aggregator_db_upsert(soc_aggregator_db_t *db, const soc_aggregator_rec_t *rec);
int soc_aggregator_db_remove(soc_aggregator_db_t *db, uint64_t id);
int soc_aggregator_db_find(const soc_aggregator_db_t *db, uint64_t id, soc_aggregator_rec_t *out);
size_t soc_aggregator_db_scan(const soc_aggregator_db_t *db, uint32_t min_sev, soc_aggregator_rec_t *out, size_t max);
uint64_t soc_aggregator_hash(const void *p, size_t n);
int soc_aggregator_validate(const soc_aggregator_rec_t *rec);
int soc_aggregator_to_json(const soc_aggregator_rec_t *rec, char *buf, size_t len);
void soc_aggregator_metrics(const soc_aggregator_db_t *db, char *buf, size_t len);
int soc_aggregator_correlate(soc_aggregator_db_t *db, const soc_aggregator_rec_t *seed, soc_aggregator_rec_t *out, size_t max);
int soc_aggregator_fn_000(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_001(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_002(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_003(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_004(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_005(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_006(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_007(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_008(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_009(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_010(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_011(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_012(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_013(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_014(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_015(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_016(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_017(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_018(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_019(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_020(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_021(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_022(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_023(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_024(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_025(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_026(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_027(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_028(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_029(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_030(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_031(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_032(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_033(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_034(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_035(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_036(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_037(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_038(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_039(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_040(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_041(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_042(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_043(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_044(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_045(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_046(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_047(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_048(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_049(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_050(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_051(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_052(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_053(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_054(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_055(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_056(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_057(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_058(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_059(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_060(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_061(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_062(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_063(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_064(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_065(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_066(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_067(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_068(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_069(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_070(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_aggregator_fn_071(soc_aggregator_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_ANALYTICS_AGGREGATOR_H */
