#ifndef SOC_NETWORK_SEC_DNS_INSPECT_H
#define SOC_NETWORK_SEC_DNS_INSPECT_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_DNS_INSPECT_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_dns_inspect_rec_t;

typedef struct { soc_dns_inspect_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_dns_inspect_db_t;

soc_dns_inspect_db_t *soc_dns_inspect_db_create(size_t n);
void soc_dns_inspect_db_destroy(soc_dns_inspect_db_t *db);
int soc_dns_inspect_db_upsert(soc_dns_inspect_db_t *db, const soc_dns_inspect_rec_t *rec);
int soc_dns_inspect_db_remove(soc_dns_inspect_db_t *db, uint64_t id);
int soc_dns_inspect_db_find(const soc_dns_inspect_db_t *db, uint64_t id, soc_dns_inspect_rec_t *out);
size_t soc_dns_inspect_db_scan(const soc_dns_inspect_db_t *db, uint32_t min_sev, soc_dns_inspect_rec_t *out, size_t max);
uint64_t soc_dns_inspect_hash(const void *p, size_t n);
int soc_dns_inspect_validate(const soc_dns_inspect_rec_t *rec);
int soc_dns_inspect_to_json(const soc_dns_inspect_rec_t *rec, char *buf, size_t len);
void soc_dns_inspect_metrics(const soc_dns_inspect_db_t *db, char *buf, size_t len);
int soc_dns_inspect_correlate(soc_dns_inspect_db_t *db, const soc_dns_inspect_rec_t *seed, soc_dns_inspect_rec_t *out, size_t max);
int soc_dns_inspect_fn_000(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_001(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_002(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_003(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_004(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_005(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_006(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_007(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_008(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_009(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_010(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_011(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_012(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_013(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_014(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_015(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_016(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_017(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_018(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_019(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_020(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_021(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_022(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_023(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_024(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_025(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_026(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_027(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_028(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_029(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_030(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_031(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_032(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_033(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_034(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_035(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_036(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_037(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_038(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_039(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_040(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_041(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_042(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_043(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_044(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_045(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_046(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_047(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_048(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_049(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_050(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_051(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_052(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_053(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_054(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_055(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_056(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_057(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_058(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_059(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_060(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_061(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_062(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_063(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_064(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_065(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_066(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_067(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_068(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_069(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_070(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_dns_inspect_fn_071(soc_dns_inspect_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_NETWORK_SEC_DNS_INSPECT_H */
