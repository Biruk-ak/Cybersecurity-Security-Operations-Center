#ifndef SOC_NETWORK_SEC_BEACON_H
#define SOC_NETWORK_SEC_BEACON_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_BEACON_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_beacon_rec_t;

typedef struct { soc_beacon_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_beacon_db_t;

soc_beacon_db_t *soc_beacon_db_create(size_t n);
void soc_beacon_db_destroy(soc_beacon_db_t *db);
int soc_beacon_db_upsert(soc_beacon_db_t *db, const soc_beacon_rec_t *rec);
int soc_beacon_db_remove(soc_beacon_db_t *db, uint64_t id);
int soc_beacon_db_find(const soc_beacon_db_t *db, uint64_t id, soc_beacon_rec_t *out);
size_t soc_beacon_db_scan(const soc_beacon_db_t *db, uint32_t min_sev, soc_beacon_rec_t *out, size_t max);
uint64_t soc_beacon_hash(const void *p, size_t n);
int soc_beacon_validate(const soc_beacon_rec_t *rec);
int soc_beacon_to_json(const soc_beacon_rec_t *rec, char *buf, size_t len);
void soc_beacon_metrics(const soc_beacon_db_t *db, char *buf, size_t len);
int soc_beacon_correlate(soc_beacon_db_t *db, const soc_beacon_rec_t *seed, soc_beacon_rec_t *out, size_t max);
int soc_beacon_fn_000(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_001(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_002(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_003(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_004(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_005(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_006(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_007(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_008(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_009(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_010(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_011(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_012(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_013(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_014(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_015(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_016(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_017(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_018(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_019(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_020(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_021(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_022(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_023(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_024(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_025(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_026(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_027(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_028(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_029(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_030(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_031(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_032(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_033(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_034(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_035(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_036(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_037(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_038(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_039(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_040(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_041(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_042(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_043(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_044(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_045(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_046(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_047(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_048(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_049(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_050(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_051(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_052(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_053(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_054(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_055(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_056(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_057(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_058(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_059(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_060(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_061(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_062(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_063(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_064(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_065(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_066(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_067(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_068(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_069(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_070(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_beacon_fn_071(soc_beacon_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_NETWORK_SEC_BEACON_H */
