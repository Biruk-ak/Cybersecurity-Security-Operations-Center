#ifndef SOC_CORRELATION_EXT_BURST_H
#define SOC_CORRELATION_EXT_BURST_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_BURST_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_burst_rec_t;

typedef struct { soc_burst_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_burst_db_t;

soc_burst_db_t *soc_burst_db_create(size_t n);
void soc_burst_db_destroy(soc_burst_db_t *db);
int soc_burst_db_upsert(soc_burst_db_t *db, const soc_burst_rec_t *rec);
int soc_burst_db_remove(soc_burst_db_t *db, uint64_t id);
int soc_burst_db_find(const soc_burst_db_t *db, uint64_t id, soc_burst_rec_t *out);
size_t soc_burst_db_scan(const soc_burst_db_t *db, uint32_t min_sev, soc_burst_rec_t *out, size_t max);
uint64_t soc_burst_hash(const void *p, size_t n);
int soc_burst_validate(const soc_burst_rec_t *rec);
int soc_burst_to_json(const soc_burst_rec_t *rec, char *buf, size_t len);
void soc_burst_metrics(const soc_burst_db_t *db, char *buf, size_t len);
int soc_burst_correlate(soc_burst_db_t *db, const soc_burst_rec_t *seed, soc_burst_rec_t *out, size_t max);
int soc_burst_fn_000(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_001(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_002(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_003(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_004(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_005(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_006(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_007(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_008(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_009(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_010(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_011(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_012(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_013(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_014(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_015(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_016(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_017(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_018(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_019(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_020(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_021(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_022(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_023(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_024(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_025(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_026(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_027(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_028(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_029(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_030(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_031(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_032(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_033(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_034(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_035(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_036(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_037(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_038(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_039(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_040(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_041(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_042(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_043(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_044(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_045(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_046(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_047(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_048(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_049(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_050(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_051(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_052(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_053(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_054(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_055(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_056(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_057(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_058(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_059(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_060(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_061(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_062(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_063(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_064(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_065(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_066(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_067(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_068(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_069(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_070(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_071(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_072(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_073(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_074(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_075(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_076(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_077(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_078(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_burst_fn_079(soc_burst_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_CORRELATION_EXT_BURST_H */
