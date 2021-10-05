#ifndef SOC_ANALYTICS_QUERY_ENGINE_H
#define SOC_ANALYTICS_QUERY_ENGINE_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_QUERY_ENGINE_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_query_engine_rec_t;

typedef struct { soc_query_engine_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_query_engine_db_t;

soc_query_engine_db_t *soc_query_engine_db_create(size_t n);
void soc_query_engine_db_destroy(soc_query_engine_db_t *db);
int soc_query_engine_db_upsert(soc_query_engine_db_t *db, const soc_query_engine_rec_t *rec);
int soc_query_engine_db_remove(soc_query_engine_db_t *db, uint64_t id);
int soc_query_engine_db_find(const soc_query_engine_db_t *db, uint64_t id, soc_query_engine_rec_t *out);
size_t soc_query_engine_db_scan(const soc_query_engine_db_t *db, uint32_t min_sev, soc_query_engine_rec_t *out, size_t max);
uint64_t soc_query_engine_hash(const void *p, size_t n);
int soc_query_engine_validate(const soc_query_engine_rec_t *rec);
int soc_query_engine_to_json(const soc_query_engine_rec_t *rec, char *buf, size_t len);
void soc_query_engine_metrics(const soc_query_engine_db_t *db, char *buf, size_t len);
int soc_query_engine_correlate(soc_query_engine_db_t *db, const soc_query_engine_rec_t *seed, soc_query_engine_rec_t *out, size_t max);
int soc_query_engine_fn_000(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_001(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_002(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_003(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_004(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_005(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_006(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_007(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_008(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_009(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_010(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_011(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_012(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_013(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_014(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_015(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_016(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_017(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_018(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_019(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_020(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_021(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_022(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_023(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_024(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_025(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_026(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_027(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_028(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_029(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_030(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_031(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_032(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_033(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_034(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_035(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_036(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_037(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_038(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_039(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_040(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_041(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_042(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_043(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_044(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_045(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_046(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_047(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_048(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_049(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_050(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_051(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_052(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_053(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_054(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_055(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_056(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_057(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_058(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_059(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_060(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_061(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_062(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_063(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_064(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_065(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_066(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_067(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_068(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_069(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_070(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_query_engine_fn_071(soc_query_engine_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_ANALYTICS_QUERY_ENGINE_H */
