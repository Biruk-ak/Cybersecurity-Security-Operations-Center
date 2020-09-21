#ifndef SOC_GATEWAY_RATE_LIMIT_H
#define SOC_GATEWAY_RATE_LIMIT_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_RATE_LIMIT_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_rate_limit_rec_t;

typedef struct { soc_rate_limit_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_rate_limit_db_t;

soc_rate_limit_db_t *soc_rate_limit_db_create(size_t n);
void soc_rate_limit_db_destroy(soc_rate_limit_db_t *db);
int soc_rate_limit_db_upsert(soc_rate_limit_db_t *db, const soc_rate_limit_rec_t *rec);
int soc_rate_limit_db_remove(soc_rate_limit_db_t *db, uint64_t id);
int soc_rate_limit_db_find(const soc_rate_limit_db_t *db, uint64_t id, soc_rate_limit_rec_t *out);
size_t soc_rate_limit_db_scan(const soc_rate_limit_db_t *db, uint32_t min_sev, soc_rate_limit_rec_t *out, size_t max);
uint64_t soc_rate_limit_hash(const void *p, size_t n);
int soc_rate_limit_validate(const soc_rate_limit_rec_t *rec);
int soc_rate_limit_to_json(const soc_rate_limit_rec_t *rec, char *buf, size_t len);
void soc_rate_limit_metrics(const soc_rate_limit_db_t *db, char *buf, size_t len);
int soc_rate_limit_correlate(soc_rate_limit_db_t *db, const soc_rate_limit_rec_t *seed, soc_rate_limit_rec_t *out, size_t max);
int soc_rate_limit_fn_000(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_001(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_002(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_003(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_004(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_005(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_006(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_007(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_008(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_009(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_010(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_011(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_012(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_013(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_014(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_015(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_016(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_017(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_018(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_019(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_020(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_021(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_022(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_023(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_024(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_025(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_026(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_027(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_028(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_029(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_030(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_031(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_032(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_033(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_034(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_035(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_036(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_037(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_038(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_039(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_040(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_041(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_042(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_043(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_044(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_045(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_046(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_047(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_048(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_049(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_050(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_051(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_052(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_053(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_054(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_055(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_056(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_057(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_058(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_059(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_060(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_061(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_062(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_063(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_rate_limit_fn_064(soc_rate_limit_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_GATEWAY_RATE_LIMIT_H */
