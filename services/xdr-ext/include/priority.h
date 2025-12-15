#ifndef SOC_XDR_EXT_PRIORITY_H
#define SOC_XDR_EXT_PRIORITY_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_PRIORITY_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_priority_rec_t;

typedef struct { soc_priority_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_priority_db_t;

soc_priority_db_t *soc_priority_db_create(size_t n);
void soc_priority_db_destroy(soc_priority_db_t *db);
int soc_priority_db_upsert(soc_priority_db_t *db, const soc_priority_rec_t *rec);
int soc_priority_db_remove(soc_priority_db_t *db, uint64_t id);
int soc_priority_db_find(const soc_priority_db_t *db, uint64_t id, soc_priority_rec_t *out);
size_t soc_priority_db_scan(const soc_priority_db_t *db, uint32_t min_sev, soc_priority_rec_t *out, size_t max);
uint64_t soc_priority_hash(const void *p, size_t n);
int soc_priority_validate(const soc_priority_rec_t *rec);
int soc_priority_to_json(const soc_priority_rec_t *rec, char *buf, size_t len);
void soc_priority_metrics(const soc_priority_db_t *db, char *buf, size_t len);
int soc_priority_correlate(soc_priority_db_t *db, const soc_priority_rec_t *seed, soc_priority_rec_t *out, size_t max);
int soc_priority_fn_000(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_001(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_002(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_003(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_004(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_005(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_006(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_007(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_008(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_009(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_010(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_011(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_012(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_013(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_014(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_015(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_016(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_017(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_018(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_019(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_020(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_021(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_022(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_023(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_024(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_025(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_026(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_027(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_028(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_029(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_030(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_031(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_032(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_033(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_034(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_035(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_036(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_037(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_038(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_039(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_040(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_041(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_042(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_043(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_044(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_045(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_046(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_047(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_048(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_049(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_050(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_051(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_052(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_053(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_054(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_055(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_056(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_057(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_058(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_059(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_060(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_061(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_062(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_063(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_064(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_065(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_066(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_067(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_068(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_069(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_070(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_071(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_072(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_073(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_074(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_075(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_076(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_077(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_078(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_priority_fn_079(soc_priority_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_XDR_EXT_PRIORITY_H */
