#ifndef SOC_SHARED_METRICS_3_H
#define SOC_SHARED_METRICS_3_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_METRICS_3_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_metrics_3_rec_t;

typedef struct { soc_metrics_3_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_metrics_3_db_t;

soc_metrics_3_db_t *soc_metrics_3_db_create(size_t n);
void soc_metrics_3_db_destroy(soc_metrics_3_db_t *db);
int soc_metrics_3_db_upsert(soc_metrics_3_db_t *db, const soc_metrics_3_rec_t *rec);
int soc_metrics_3_db_remove(soc_metrics_3_db_t *db, uint64_t id);
int soc_metrics_3_db_find(const soc_metrics_3_db_t *db, uint64_t id, soc_metrics_3_rec_t *out);
size_t soc_metrics_3_db_scan(const soc_metrics_3_db_t *db, uint32_t min_sev, soc_metrics_3_rec_t *out, size_t max);
uint64_t soc_metrics_3_hash(const void *p, size_t n);
int soc_metrics_3_validate(const soc_metrics_3_rec_t *rec);
int soc_metrics_3_to_json(const soc_metrics_3_rec_t *rec, char *buf, size_t len);
void soc_metrics_3_metrics(const soc_metrics_3_db_t *db, char *buf, size_t len);
int soc_metrics_3_correlate(soc_metrics_3_db_t *db, const soc_metrics_3_rec_t *seed, soc_metrics_3_rec_t *out, size_t max);
int soc_metrics_3_fn_000(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_001(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_002(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_003(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_004(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_005(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_006(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_007(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_008(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_009(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_010(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_011(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_012(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_013(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_014(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_015(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_016(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_017(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_018(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_019(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_020(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_021(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_022(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_023(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_024(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_025(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_026(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_027(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_028(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_029(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_030(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_031(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_032(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_033(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_034(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_035(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_036(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_037(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_038(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_039(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_040(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_041(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_042(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_043(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_044(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_045(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_046(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_047(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_048(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_049(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_050(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_051(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_052(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_053(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_054(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_055(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_056(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_057(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_058(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_059(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_060(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_061(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_062(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_063(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_064(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_065(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_066(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_067(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_068(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_069(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_070(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_071(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_072(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_073(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_metrics_3_fn_074(soc_metrics_3_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_SHARED_METRICS_3_H */
