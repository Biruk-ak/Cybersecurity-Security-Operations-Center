#ifndef SOC_XDR_EXT_CONTEXT_H
#define SOC_XDR_EXT_CONTEXT_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_CONTEXT_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_context_rec_t;

typedef struct { soc_context_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_context_db_t;

soc_context_db_t *soc_context_db_create(size_t n);
void soc_context_db_destroy(soc_context_db_t *db);
int soc_context_db_upsert(soc_context_db_t *db, const soc_context_rec_t *rec);
int soc_context_db_remove(soc_context_db_t *db, uint64_t id);
int soc_context_db_find(const soc_context_db_t *db, uint64_t id, soc_context_rec_t *out);
size_t soc_context_db_scan(const soc_context_db_t *db, uint32_t min_sev, soc_context_rec_t *out, size_t max);
uint64_t soc_context_hash(const void *p, size_t n);
int soc_context_validate(const soc_context_rec_t *rec);
int soc_context_to_json(const soc_context_rec_t *rec, char *buf, size_t len);
void soc_context_metrics(const soc_context_db_t *db, char *buf, size_t len);
int soc_context_correlate(soc_context_db_t *db, const soc_context_rec_t *seed, soc_context_rec_t *out, size_t max);
int soc_context_fn_000(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_001(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_002(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_003(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_004(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_005(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_006(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_007(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_008(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_009(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_010(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_011(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_012(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_013(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_014(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_015(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_016(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_017(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_018(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_019(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_020(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_021(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_022(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_023(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_024(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_025(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_026(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_027(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_028(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_029(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_030(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_031(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_032(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_033(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_034(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_035(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_036(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_037(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_038(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_039(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_040(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_041(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_042(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_043(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_044(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_045(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_046(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_047(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_048(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_049(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_050(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_051(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_052(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_053(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_054(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_055(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_056(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_057(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_058(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_059(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_060(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_061(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_062(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_063(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_064(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_065(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_066(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_067(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_068(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_069(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_070(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_071(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_072(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_073(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_074(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_075(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_076(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_077(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_078(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_context_fn_079(soc_context_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_XDR_EXT_CONTEXT_H */
