#ifndef SOC_GATEWAY_WAF_H
#define SOC_GATEWAY_WAF_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_WAF_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_waf_rec_t;

typedef struct { soc_waf_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_waf_db_t;

soc_waf_db_t *soc_waf_db_create(size_t n);
void soc_waf_db_destroy(soc_waf_db_t *db);
int soc_waf_db_upsert(soc_waf_db_t *db, const soc_waf_rec_t *rec);
int soc_waf_db_remove(soc_waf_db_t *db, uint64_t id);
int soc_waf_db_find(const soc_waf_db_t *db, uint64_t id, soc_waf_rec_t *out);
size_t soc_waf_db_scan(const soc_waf_db_t *db, uint32_t min_sev, soc_waf_rec_t *out, size_t max);
uint64_t soc_waf_hash(const void *p, size_t n);
int soc_waf_validate(const soc_waf_rec_t *rec);
int soc_waf_to_json(const soc_waf_rec_t *rec, char *buf, size_t len);
void soc_waf_metrics(const soc_waf_db_t *db, char *buf, size_t len);
int soc_waf_correlate(soc_waf_db_t *db, const soc_waf_rec_t *seed, soc_waf_rec_t *out, size_t max);
int soc_waf_fn_000(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_001(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_002(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_003(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_004(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_005(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_006(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_007(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_008(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_009(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_010(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_011(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_012(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_013(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_014(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_015(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_016(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_017(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_018(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_019(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_020(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_021(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_022(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_023(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_024(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_025(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_026(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_027(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_028(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_029(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_030(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_031(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_032(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_033(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_034(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_035(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_036(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_037(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_038(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_039(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_040(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_041(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_042(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_043(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_044(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_045(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_046(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_047(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_048(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_049(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_050(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_051(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_052(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_053(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_054(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_055(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_056(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_057(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_058(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_059(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_060(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_061(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_062(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_063(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_waf_fn_064(soc_waf_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_GATEWAY_WAF_H */
