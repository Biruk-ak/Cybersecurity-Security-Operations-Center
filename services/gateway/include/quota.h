#ifndef SOC_GATEWAY_QUOTA_H
#define SOC_GATEWAY_QUOTA_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_QUOTA_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_quota_rec_t;

typedef struct { soc_quota_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_quota_db_t;

soc_quota_db_t *soc_quota_db_create(size_t n);
void soc_quota_db_destroy(soc_quota_db_t *db);
int soc_quota_db_upsert(soc_quota_db_t *db, const soc_quota_rec_t *rec);
int soc_quota_db_remove(soc_quota_db_t *db, uint64_t id);
int soc_quota_db_find(const soc_quota_db_t *db, uint64_t id, soc_quota_rec_t *out);
size_t soc_quota_db_scan(const soc_quota_db_t *db, uint32_t min_sev, soc_quota_rec_t *out, size_t max);
uint64_t soc_quota_hash(const void *p, size_t n);
int soc_quota_validate(const soc_quota_rec_t *rec);
int soc_quota_to_json(const soc_quota_rec_t *rec, char *buf, size_t len);
void soc_quota_metrics(const soc_quota_db_t *db, char *buf, size_t len);
int soc_quota_correlate(soc_quota_db_t *db, const soc_quota_rec_t *seed, soc_quota_rec_t *out, size_t max);
int soc_quota_fn_000(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_001(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_002(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_003(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_004(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_005(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_006(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_007(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_008(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_009(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_010(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_011(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_012(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_013(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_014(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_015(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_016(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_017(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_018(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_019(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_020(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_021(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_022(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_023(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_024(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_025(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_026(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_027(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_028(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_029(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_030(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_031(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_032(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_033(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_034(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_035(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_036(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_037(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_038(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_039(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_040(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_041(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_042(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_043(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_044(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_045(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_046(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_047(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_048(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_049(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_050(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_051(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_052(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_053(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_054(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_055(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_056(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_057(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_058(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_059(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_060(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_061(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_062(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_063(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_quota_fn_064(soc_quota_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_GATEWAY_QUOTA_H */
