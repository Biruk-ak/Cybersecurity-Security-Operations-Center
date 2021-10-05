#ifndef SOC_ANALYTICS_ROLLUP_H
#define SOC_ANALYTICS_ROLLUP_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_ROLLUP_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_rollup_rec_t;

typedef struct { soc_rollup_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_rollup_db_t;

soc_rollup_db_t *soc_rollup_db_create(size_t n);
void soc_rollup_db_destroy(soc_rollup_db_t *db);
int soc_rollup_db_upsert(soc_rollup_db_t *db, const soc_rollup_rec_t *rec);
int soc_rollup_db_remove(soc_rollup_db_t *db, uint64_t id);
int soc_rollup_db_find(const soc_rollup_db_t *db, uint64_t id, soc_rollup_rec_t *out);
size_t soc_rollup_db_scan(const soc_rollup_db_t *db, uint32_t min_sev, soc_rollup_rec_t *out, size_t max);
uint64_t soc_rollup_hash(const void *p, size_t n);
int soc_rollup_validate(const soc_rollup_rec_t *rec);
int soc_rollup_to_json(const soc_rollup_rec_t *rec, char *buf, size_t len);
void soc_rollup_metrics(const soc_rollup_db_t *db, char *buf, size_t len);
int soc_rollup_correlate(soc_rollup_db_t *db, const soc_rollup_rec_t *seed, soc_rollup_rec_t *out, size_t max);
int soc_rollup_fn_000(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_001(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_002(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_003(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_004(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_005(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_006(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_007(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_008(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_009(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_010(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_011(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_012(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_013(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_014(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_015(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_016(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_017(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_018(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_019(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_020(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_021(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_022(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_023(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_024(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_025(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_026(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_027(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_028(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_029(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_030(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_031(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_032(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_033(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_034(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_035(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_036(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_037(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_038(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_039(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_040(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_041(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_042(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_043(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_044(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_045(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_046(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_047(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_048(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_049(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_050(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_051(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_052(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_053(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_054(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_055(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_056(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_057(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_058(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_059(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_060(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_061(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_062(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_063(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_064(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_065(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_066(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_067(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_068(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_069(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_070(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rollup_fn_071(soc_rollup_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_ANALYTICS_ROLLUP_H */
