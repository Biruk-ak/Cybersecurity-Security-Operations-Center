#ifndef SOC_AI_DETECTION_CLUSTER_H
#define SOC_AI_DETECTION_CLUSTER_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_CLUSTER_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_cluster_rec_t;

typedef struct { soc_cluster_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_cluster_db_t;

soc_cluster_db_t *soc_cluster_db_create(size_t n);
void soc_cluster_db_destroy(soc_cluster_db_t *db);
int soc_cluster_db_upsert(soc_cluster_db_t *db, const soc_cluster_rec_t *rec);
int soc_cluster_db_remove(soc_cluster_db_t *db, uint64_t id);
int soc_cluster_db_find(const soc_cluster_db_t *db, uint64_t id, soc_cluster_rec_t *out);
size_t soc_cluster_db_scan(const soc_cluster_db_t *db, uint32_t min_sev, soc_cluster_rec_t *out, size_t max);
uint64_t soc_cluster_hash(const void *p, size_t n);
int soc_cluster_validate(const soc_cluster_rec_t *rec);
int soc_cluster_to_json(const soc_cluster_rec_t *rec, char *buf, size_t len);
void soc_cluster_metrics(const soc_cluster_db_t *db, char *buf, size_t len);
int soc_cluster_correlate(soc_cluster_db_t *db, const soc_cluster_rec_t *seed, soc_cluster_rec_t *out, size_t max);
int soc_cluster_fn_000(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_001(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_002(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_003(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_004(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_005(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_006(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_007(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_008(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_009(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_010(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_011(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_012(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_013(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_014(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_015(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_016(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_017(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_018(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_019(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_020(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_021(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_022(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_023(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_024(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_025(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_026(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_027(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_028(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_029(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_030(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_031(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_032(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_033(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_034(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_035(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_036(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_037(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_038(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_039(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_040(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_041(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_042(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_043(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_044(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_045(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_046(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_047(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_048(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_049(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_050(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_051(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_052(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_053(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_054(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_055(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_056(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_057(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_058(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_059(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_060(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_061(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_062(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_063(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_064(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_065(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_066(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_067(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_068(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_069(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_070(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cluster_fn_071(soc_cluster_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_AI_DETECTION_CLUSTER_H */
