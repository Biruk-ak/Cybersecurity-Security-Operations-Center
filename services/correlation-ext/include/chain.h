#ifndef SOC_CORRELATION_EXT_CHAIN_H
#define SOC_CORRELATION_EXT_CHAIN_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_CHAIN_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_chain_rec_t;

typedef struct { soc_chain_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_chain_db_t;

soc_chain_db_t *soc_chain_db_create(size_t n);
void soc_chain_db_destroy(soc_chain_db_t *db);
int soc_chain_db_upsert(soc_chain_db_t *db, const soc_chain_rec_t *rec);
int soc_chain_db_remove(soc_chain_db_t *db, uint64_t id);
int soc_chain_db_find(const soc_chain_db_t *db, uint64_t id, soc_chain_rec_t *out);
size_t soc_chain_db_scan(const soc_chain_db_t *db, uint32_t min_sev, soc_chain_rec_t *out, size_t max);
uint64_t soc_chain_hash(const void *p, size_t n);
int soc_chain_validate(const soc_chain_rec_t *rec);
int soc_chain_to_json(const soc_chain_rec_t *rec, char *buf, size_t len);
void soc_chain_metrics(const soc_chain_db_t *db, char *buf, size_t len);
int soc_chain_correlate(soc_chain_db_t *db, const soc_chain_rec_t *seed, soc_chain_rec_t *out, size_t max);
int soc_chain_fn_000(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_001(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_002(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_003(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_004(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_005(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_006(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_007(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_008(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_009(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_010(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_011(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_012(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_013(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_014(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_015(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_016(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_017(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_018(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_019(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_020(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_021(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_022(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_023(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_024(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_025(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_026(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_027(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_028(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_029(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_030(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_031(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_032(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_033(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_034(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_035(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_036(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_037(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_038(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_039(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_040(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_041(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_042(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_043(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_044(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_045(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_046(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_047(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_048(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_049(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_050(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_051(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_052(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_053(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_054(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_055(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_056(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_057(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_058(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_059(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_060(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_061(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_062(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_063(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_064(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_065(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_066(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_067(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_068(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_069(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_070(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_071(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_072(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_073(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_074(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_075(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_076(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_077(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_078(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_chain_fn_079(soc_chain_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_CORRELATION_EXT_CHAIN_H */
