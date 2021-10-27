#ifndef SOC_AI_DETECTION_ANOMALY_SCORE_H
#define SOC_AI_DETECTION_ANOMALY_SCORE_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_ANOMALY_SCORE_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_anomaly_score_rec_t;

typedef struct { soc_anomaly_score_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_anomaly_score_db_t;

soc_anomaly_score_db_t *soc_anomaly_score_db_create(size_t n);
void soc_anomaly_score_db_destroy(soc_anomaly_score_db_t *db);
int soc_anomaly_score_db_upsert(soc_anomaly_score_db_t *db, const soc_anomaly_score_rec_t *rec);
int soc_anomaly_score_db_remove(soc_anomaly_score_db_t *db, uint64_t id);
int soc_anomaly_score_db_find(const soc_anomaly_score_db_t *db, uint64_t id, soc_anomaly_score_rec_t *out);
size_t soc_anomaly_score_db_scan(const soc_anomaly_score_db_t *db, uint32_t min_sev, soc_anomaly_score_rec_t *out, size_t max);
uint64_t soc_anomaly_score_hash(const void *p, size_t n);
int soc_anomaly_score_validate(const soc_anomaly_score_rec_t *rec);
int soc_anomaly_score_to_json(const soc_anomaly_score_rec_t *rec, char *buf, size_t len);
void soc_anomaly_score_metrics(const soc_anomaly_score_db_t *db, char *buf, size_t len);
int soc_anomaly_score_correlate(soc_anomaly_score_db_t *db, const soc_anomaly_score_rec_t *seed, soc_anomaly_score_rec_t *out, size_t max);
int soc_anomaly_score_fn_000(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_001(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_002(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_003(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_004(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_005(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_006(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_007(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_008(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_009(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_010(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_011(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_012(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_013(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_014(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_015(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_016(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_017(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_018(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_019(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_020(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_021(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_022(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_023(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_024(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_025(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_026(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_027(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_028(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_029(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_030(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_031(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_032(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_033(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_034(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_035(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_036(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_037(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_038(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_039(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_040(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_041(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_042(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_043(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_044(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_045(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_046(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_047(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_048(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_049(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_050(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_051(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_052(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_053(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_054(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_055(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_056(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_057(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_058(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_059(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_060(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_061(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_062(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_063(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_064(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_065(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_066(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_067(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_068(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_069(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_070(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_anomaly_score_fn_071(soc_anomaly_score_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_AI_DETECTION_ANOMALY_SCORE_H */
