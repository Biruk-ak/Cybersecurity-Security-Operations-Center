#ifndef SOC_XDR_EXT_RESPONSE_H
#define SOC_XDR_EXT_RESPONSE_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_RESPONSE_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_response_rec_t;

typedef struct { soc_response_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_response_db_t;

soc_response_db_t *soc_response_db_create(size_t n);
void soc_response_db_destroy(soc_response_db_t *db);
int soc_response_db_upsert(soc_response_db_t *db, const soc_response_rec_t *rec);
int soc_response_db_remove(soc_response_db_t *db, uint64_t id);
int soc_response_db_find(const soc_response_db_t *db, uint64_t id, soc_response_rec_t *out);
size_t soc_response_db_scan(const soc_response_db_t *db, uint32_t min_sev, soc_response_rec_t *out, size_t max);
uint64_t soc_response_hash(const void *p, size_t n);
int soc_response_validate(const soc_response_rec_t *rec);
int soc_response_to_json(const soc_response_rec_t *rec, char *buf, size_t len);
void soc_response_metrics(const soc_response_db_t *db, char *buf, size_t len);
int soc_response_correlate(soc_response_db_t *db, const soc_response_rec_t *seed, soc_response_rec_t *out, size_t max);
int soc_response_fn_000(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_001(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_002(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_003(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_004(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_005(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_006(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_007(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_008(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_009(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_010(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_011(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_012(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_013(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_014(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_015(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_016(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_017(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_018(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_019(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_020(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_021(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_022(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_023(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_024(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_025(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_026(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_027(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_028(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_029(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_030(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_031(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_032(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_033(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_034(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_035(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_036(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_037(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_038(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_039(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_040(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_041(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_042(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_043(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_044(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_045(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_046(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_047(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_048(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_049(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_050(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_051(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_052(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_053(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_054(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_055(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_056(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_057(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_058(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_059(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_060(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_061(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_062(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_063(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_064(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_065(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_066(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_067(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_068(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_069(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_070(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_071(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_072(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_073(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_074(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_075(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_076(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_077(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_078(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_response_fn_079(soc_response_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_XDR_EXT_RESPONSE_H */
