#ifndef SOC_XDR_EXT_FUSE_H
#define SOC_XDR_EXT_FUSE_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_FUSE_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_fuse_rec_t;

typedef struct { soc_fuse_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_fuse_db_t;

soc_fuse_db_t *soc_fuse_db_create(size_t n);
void soc_fuse_db_destroy(soc_fuse_db_t *db);
int soc_fuse_db_upsert(soc_fuse_db_t *db, const soc_fuse_rec_t *rec);
int soc_fuse_db_remove(soc_fuse_db_t *db, uint64_t id);
int soc_fuse_db_find(const soc_fuse_db_t *db, uint64_t id, soc_fuse_rec_t *out);
size_t soc_fuse_db_scan(const soc_fuse_db_t *db, uint32_t min_sev, soc_fuse_rec_t *out, size_t max);
uint64_t soc_fuse_hash(const void *p, size_t n);
int soc_fuse_validate(const soc_fuse_rec_t *rec);
int soc_fuse_to_json(const soc_fuse_rec_t *rec, char *buf, size_t len);
void soc_fuse_metrics(const soc_fuse_db_t *db, char *buf, size_t len);
int soc_fuse_correlate(soc_fuse_db_t *db, const soc_fuse_rec_t *seed, soc_fuse_rec_t *out, size_t max);
int soc_fuse_fn_000(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_001(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_002(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_003(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_004(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_005(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_006(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_007(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_008(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_009(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_010(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_011(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_012(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_013(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_014(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_015(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_016(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_017(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_018(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_019(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_020(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_021(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_022(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_023(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_024(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_025(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_026(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_027(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_028(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_029(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_030(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_031(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_032(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_033(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_034(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_035(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_036(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_037(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_038(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_039(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_040(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_041(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_042(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_043(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_044(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_045(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_046(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_047(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_048(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_049(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_050(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_051(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_052(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_053(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_054(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_055(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_056(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_057(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_058(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_059(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_060(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_061(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_062(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_063(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_064(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_065(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_066(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_067(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_068(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_069(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_070(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_071(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_072(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_073(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_074(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_075(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_076(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_077(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_078(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_fuse_fn_079(soc_fuse_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_XDR_EXT_FUSE_H */
