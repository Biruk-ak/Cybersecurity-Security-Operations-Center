#ifndef SOC_AI_DETECTION_EMBEDDING_H
#define SOC_AI_DETECTION_EMBEDDING_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_EMBEDDING_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_embedding_rec_t;

typedef struct { soc_embedding_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_embedding_db_t;

soc_embedding_db_t *soc_embedding_db_create(size_t n);
void soc_embedding_db_destroy(soc_embedding_db_t *db);
int soc_embedding_db_upsert(soc_embedding_db_t *db, const soc_embedding_rec_t *rec);
int soc_embedding_db_remove(soc_embedding_db_t *db, uint64_t id);
int soc_embedding_db_find(const soc_embedding_db_t *db, uint64_t id, soc_embedding_rec_t *out);
size_t soc_embedding_db_scan(const soc_embedding_db_t *db, uint32_t min_sev, soc_embedding_rec_t *out, size_t max);
uint64_t soc_embedding_hash(const void *p, size_t n);
int soc_embedding_validate(const soc_embedding_rec_t *rec);
int soc_embedding_to_json(const soc_embedding_rec_t *rec, char *buf, size_t len);
void soc_embedding_metrics(const soc_embedding_db_t *db, char *buf, size_t len);
int soc_embedding_correlate(soc_embedding_db_t *db, const soc_embedding_rec_t *seed, soc_embedding_rec_t *out, size_t max);
int soc_embedding_fn_000(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_001(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_002(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_003(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_004(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_005(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_006(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_007(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_008(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_009(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_010(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_011(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_012(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_013(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_014(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_015(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_016(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_017(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_018(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_019(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_020(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_021(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_022(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_023(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_024(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_025(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_026(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_027(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_028(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_029(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_030(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_031(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_032(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_033(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_034(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_035(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_036(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_037(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_038(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_039(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_040(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_041(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_042(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_043(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_044(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_045(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_046(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_047(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_048(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_049(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_050(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_051(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_052(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_053(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_054(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_055(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_056(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_057(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_058(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_059(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_060(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_061(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_062(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_063(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_064(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_065(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_066(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_067(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_068(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_069(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_070(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_embedding_fn_071(soc_embedding_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_AI_DETECTION_EMBEDDING_H */
