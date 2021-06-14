#ifndef SOC_VULN_MGMT_CVE_DB_H
#define SOC_VULN_MGMT_CVE_DB_H
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SOC_CVE_DB_MAX 8192

typedef struct {
  uint64_t id; uint64_t tenant_id; uint32_t severity; uint32_t flags;
  int64_t created_at; int64_t updated_at; double score; double confidence;
  char name[256]; char description[2048]; char source[128];
  char mitre[64]; uint8_t payload[4096]; size_t payload_len;
} soc_cve_db_rec_t;

typedef struct { soc_cve_db_rec_t *items; size_t capacity; size_t count; uint64_t seq; } soc_cve_db_db_t;

soc_cve_db_db_t *soc_cve_db_db_create(size_t n);
void soc_cve_db_db_destroy(soc_cve_db_db_t *db);
int soc_cve_db_db_upsert(soc_cve_db_db_t *db, const soc_cve_db_rec_t *rec);
int soc_cve_db_db_remove(soc_cve_db_db_t *db, uint64_t id);
int soc_cve_db_db_find(const soc_cve_db_db_t *db, uint64_t id, soc_cve_db_rec_t *out);
size_t soc_cve_db_db_scan(const soc_cve_db_db_t *db, uint32_t min_sev, soc_cve_db_rec_t *out, size_t max);
uint64_t soc_cve_db_hash(const void *p, size_t n);
int soc_cve_db_validate(const soc_cve_db_rec_t *rec);
int soc_cve_db_to_json(const soc_cve_db_rec_t *rec, char *buf, size_t len);
void soc_cve_db_metrics(const soc_cve_db_db_t *db, char *buf, size_t len);
int soc_cve_db_correlate(soc_cve_db_db_t *db, const soc_cve_db_rec_t *seed, soc_cve_db_rec_t *out, size_t max);
int soc_cve_db_fn_000(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_001(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_002(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_003(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_004(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_005(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_006(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_007(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_008(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_009(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_010(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_011(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_012(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_013(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_014(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_015(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_016(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_017(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_018(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_019(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_020(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_021(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_022(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_023(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_024(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_025(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_026(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_027(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_028(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_029(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_030(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_031(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_032(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_033(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_034(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_035(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_036(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_037(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_038(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_039(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_040(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_041(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_042(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_043(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_044(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_045(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_046(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_047(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_048(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_049(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_050(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_051(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_052(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_053(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_054(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_055(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_056(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_057(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_058(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_059(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_060(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_061(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_062(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_063(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_064(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_065(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_066(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_067(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_068(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_069(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_070(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);
int soc_cve_db_fn_071(soc_cve_db_db_t *db, uint64_t a, const void *b, size_t blen);

#endif /* SOC_VULN_MGMT_CVE_DB_H */
