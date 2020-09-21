#ifndef SOC_GATEWAY_ROUTER_H
#define SOC_GATEWAY_ROUTER_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_ROUTER_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_router_rec_t;

typedef struct { soc_router_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_router_db_t;

soc_router_db_t *soc_router_db_create(size_t n);
void soc_router_db_destroy(soc_router_db_t *db);
int soc_router_db_upsert(soc_router_db_t *db, const soc_router_rec_t *rec);
int soc_router_db_remove(soc_router_db_t *db, uint64_t id);
int soc_router_db_find(const soc_router_db_t *db, uint64_t id, soc_router_rec_t *out);
size_t soc_router_db_scan(const soc_router_db_t *db, uint32_t min_sev, soc_router_rec_t *out, size_t max);
uint64_t soc_router_hash(const void *p, size_t n);
int soc_router_validate(const soc_router_rec_t *rec);
int soc_router_to_json(const soc_router_rec_t *rec, char *buf, size_t len);
void soc_router_metrics(const soc_router_db_t *db, char *buf, size_t len);
int soc_router_correlate(soc_router_db_t *db, const soc_router_rec_t *seed, soc_router_rec_t *out, size_t max);
int soc_router_fn_000(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_001(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_002(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_003(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_004(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_005(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_006(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_007(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_008(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_009(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_010(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_011(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_012(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_013(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_014(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_015(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_016(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_017(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_018(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_019(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_020(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_021(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_022(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_023(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_024(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_025(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_026(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_027(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_028(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_029(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_030(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_031(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_032(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_033(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_034(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_035(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_036(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_037(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_038(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_039(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_040(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_041(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_042(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_043(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_044(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_045(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_046(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_047(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_048(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_049(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_050(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_051(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_052(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_053(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_054(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_055(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_056(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_057(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_058(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_059(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_060(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_061(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_062(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_063(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_router_fn_064(soc_router_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_GATEWAY_ROUTER_H */
