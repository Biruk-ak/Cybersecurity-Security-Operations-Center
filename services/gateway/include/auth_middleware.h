#ifndef SOC_GATEWAY_AUTH_MIDDLEWARE_H
#define SOC_GATEWAY_AUTH_MIDDLEWARE_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_AUTH_MIDDLEWARE_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_auth_middleware_rec_t;

typedef struct { soc_auth_middleware_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_auth_middleware_db_t;

soc_auth_middleware_db_t *soc_auth_middleware_db_create(size_t n);
void soc_auth_middleware_db_destroy(soc_auth_middleware_db_t *db);
int soc_auth_middleware_db_upsert(soc_auth_middleware_db_t *db, const soc_auth_middleware_rec_t *rec);
int soc_auth_middleware_db_remove(soc_auth_middleware_db_t *db, uint64_t id);
int soc_auth_middleware_db_find(const soc_auth_middleware_db_t *db, uint64_t id, soc_auth_middleware_rec_t *out);
size_t soc_auth_middleware_db_scan(const soc_auth_middleware_db_t *db, uint32_t min_sev, soc_auth_middleware_rec_t *out, size_t max);
uint64_t soc_auth_middleware_hash(const void *p, size_t n);
int soc_auth_middleware_validate(const soc_auth_middleware_rec_t *rec);
int soc_auth_middleware_to_json(const soc_auth_middleware_rec_t *rec, char *buf, size_t len);
void soc_auth_middleware_metrics(const soc_auth_middleware_db_t *db, char *buf, size_t len);
int soc_auth_middleware_correlate(soc_auth_middleware_db_t *db, const soc_auth_middleware_rec_t *seed, soc_auth_middleware_rec_t *out, size_t max);
int soc_auth_middleware_fn_000(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_001(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_002(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_003(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_004(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_005(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_006(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_007(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_008(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_009(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_010(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_011(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_012(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_013(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_014(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_015(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_016(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_017(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_018(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_019(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_020(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_021(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_022(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_023(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_024(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_025(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_026(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_027(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_028(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_029(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_030(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_031(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_032(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_033(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_034(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_035(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_036(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_037(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_038(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_039(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_040(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_041(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_042(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_043(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_044(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_045(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_046(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_047(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_048(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_049(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_050(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_051(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_052(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_053(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_054(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_055(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_056(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_057(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_058(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_059(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_060(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_061(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_062(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_063(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_auth_middleware_fn_064(soc_auth_middleware_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_GATEWAY_AUTH_MIDDLEWARE_H */
