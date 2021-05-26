#ifndef SOC_THREAT_INTEL_IOC_STORE_H
#define SOC_THREAT_INTEL_IOC_STORE_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_IOC_STORE_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_ioc_store_rec_t;

typedef struct { soc_ioc_store_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_ioc_store_db_t;

soc_ioc_store_db_t *soc_ioc_store_db_create(size_t n);
void soc_ioc_store_db_destroy(soc_ioc_store_db_t *db);
int soc_ioc_store_db_upsert(soc_ioc_store_db_t *db, const soc_ioc_store_rec_t *rec);
int soc_ioc_store_db_remove(soc_ioc_store_db_t *db, uint64_t id);
int soc_ioc_store_db_find(const soc_ioc_store_db_t *db, uint64_t id, soc_ioc_store_rec_t *out);
size_t soc_ioc_store_db_scan(const soc_ioc_store_db_t *db, uint32_t min_sev, soc_ioc_store_rec_t *out, size_t max);
uint64_t soc_ioc_store_hash(const void *p, size_t n);
int soc_ioc_store_validate(const soc_ioc_store_rec_t *rec);
int soc_ioc_store_to_json(const soc_ioc_store_rec_t *rec, char *buf, size_t len);
void soc_ioc_store_metrics(const soc_ioc_store_db_t *db, char *buf, size_t len);
int soc_ioc_store_correlate(soc_ioc_store_db_t *db, const soc_ioc_store_rec_t *seed, soc_ioc_store_rec_t *out, size_t max);
int soc_ioc_store_fn_000(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_001(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_002(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_003(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_004(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_005(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_006(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_007(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_008(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_009(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_010(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_011(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_012(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_013(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_014(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_015(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_016(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_017(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_018(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_019(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_020(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_021(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_022(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_023(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_024(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_025(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_026(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_027(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_028(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_029(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_030(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_031(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_032(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_033(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_034(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_035(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_036(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_037(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_038(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_039(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_040(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_041(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_042(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_043(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_044(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_045(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_046(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_047(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_048(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_049(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_050(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_051(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_052(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_053(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_054(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_055(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_056(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_057(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_058(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_059(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_060(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_061(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_062(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_063(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_064(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_065(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_066(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_067(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_068(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_069(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_070(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_ioc_store_fn_071(soc_ioc_store_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_THREAT_INTEL_IOC_STORE_H */
