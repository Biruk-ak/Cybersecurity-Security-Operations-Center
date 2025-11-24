#ifndef SOC_CORRELATION_EXT_ENTITY_H
#define SOC_CORRELATION_EXT_ENTITY_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_ENTITY_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_entity_rec_t;

typedef struct { soc_entity_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_entity_db_t;

soc_entity_db_t *soc_entity_db_create(size_t n);
void soc_entity_db_destroy(soc_entity_db_t *db);
int soc_entity_db_upsert(soc_entity_db_t *db, const soc_entity_rec_t *rec);
int soc_entity_db_remove(soc_entity_db_t *db, uint64_t id);
int soc_entity_db_find(const soc_entity_db_t *db, uint64_t id, soc_entity_rec_t *out);
size_t soc_entity_db_scan(const soc_entity_db_t *db, uint32_t min_sev, soc_entity_rec_t *out, size_t max);
uint64_t soc_entity_hash(const void *p, size_t n);
int soc_entity_validate(const soc_entity_rec_t *rec);
int soc_entity_to_json(const soc_entity_rec_t *rec, char *buf, size_t len);
void soc_entity_metrics(const soc_entity_db_t *db, char *buf, size_t len);
int soc_entity_correlate(soc_entity_db_t *db, const soc_entity_rec_t *seed, soc_entity_rec_t *out, size_t max);
int soc_entity_fn_000(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_001(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_002(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_003(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_004(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_005(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_006(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_007(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_008(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_009(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_010(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_011(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_012(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_013(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_014(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_015(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_016(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_017(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_018(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_019(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_020(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_021(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_022(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_023(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_024(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_025(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_026(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_027(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_028(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_029(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_030(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_031(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_032(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_033(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_034(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_035(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_036(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_037(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_038(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_039(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_040(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_041(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_042(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_043(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_044(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_045(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_046(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_047(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_048(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_049(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_050(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_051(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_052(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_053(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_054(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_055(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_056(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_057(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_058(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_059(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_060(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_061(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_062(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_063(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_064(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_065(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_066(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_067(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_068(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_069(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_070(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_071(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_072(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_073(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_074(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_075(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_076(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_077(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_078(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_entity_fn_079(soc_entity_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_CORRELATION_EXT_ENTITY_H */
