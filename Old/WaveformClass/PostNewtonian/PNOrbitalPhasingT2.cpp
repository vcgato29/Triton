#include "PNOrbitalPhasingT2.hpp"

#ifndef EulerGamma
#define EulerGamma 0.5772156649015328606065120900824024
#endif // EulerGamma
#include "VectorFunctions.hpp"
#include "Roots.hpp"
#include <cmath>
using namespace std;


class T2 {
private:
  double delta;
  double nu;
  double chis;
  double chia;
  double PNOrder;
  
public:
  T2(const double idelta, const double ichis, const double ichia, const double PNPhaseOrder)
    : delta(idelta), nu((1.0-delta*delta)/4.0), chis(ichis), chia(ichia), PNOrder(PNPhaseOrder) {}
  
  double operator()(const double v) const {
    vector<double> t(1, 0.0);
    vector<double> Phi(1, 0.0);
    tPhi(vector<double>(1, v), t, Phi);
    return t[0];
  }
  
  void tPhi(const vector<double>& v, vector<double>& t, vector<double>& Phi) const {
    const double t0=0.0, Phi0=0.0;
    switch(int(2*PNOrder)) {
    case 0:
      t = t0-(5./(256.*nu*pow(v,8)));
      Phi = Phi0-(1./(32*nu*pow(v,5)));
      break;
      
    case 1:
      t = t0-(5./(256.*nu*pow(v,8)));
      Phi = Phi0-(1./(32*nu*pow(v,5)));
      break;
      
    case 2:
      t = t0-(5./(256.*nu*pow(v,8)))*(1 + pow(v,2)*(2.9484126984126986 + (11*nu)/3. + pow(v,2)*(16.413708191609977 + (16789*nu)/504. + (385*pow(nu,2))/24. + pow(v,2)*(121.83270306510501 + (116171767.0*nu)/338688. + (541535*pow(nu,2))/1728. + (13475*pow(nu,3))/144.))));
      Phi = Phi0-(1./(32*nu*pow(v,5)))*(1 + pow(v,2)*(3.685515873015873 + (55*nu)/12. + pow(v,2)*(41.03427047902494 + (83945*nu)/1008. + (1925*pow(nu,2))/48. + pow(v,2)*(-152.29087883138126 - (580858835.0*nu)/1.354752e6 - (2707675*pow(nu,2))/6912. - (67375*pow(nu,3))/576.))));
      break;
      
    case 3:
      t = t0-(5./(256.*nu*pow(v,8)))*(1 + pow(v,2)*(2.9484126984126986 + (11*nu)/3. + v*((226*chis)/15. - (32*M_PI)/5. + (226*chia*delta)/15. - (152*chis*nu)/15. + v*(16.413708191609977 + (16789*nu)/504. + (385*pow(nu,2))/24. + v*((82715*chis)/756. - (3980*M_PI)/63. + (82715*chia*delta)/756. + (352*chis*nu)/27. - (544*M_PI*nu)/9. + (2522*chia*delta*nu)/27. - (1924*chis*pow(nu,2))/27. + v*(121.83270306510501 + (1243*pow(chis,2))/12. - (584*chis*M_PI)/3. + 64*pow(M_PI,2) + (1243*chia*chis*delta)/6. - (584*chia*M_PI*delta)/3. + (1243*pow(chia,2)*pow(delta,2))/12. + (116171767.0*nu)/338688. - (548*pow(chis,2)*nu)/3. + (448*chis*M_PI*nu)/3. - (548*chia*chis*delta*nu)/3. + (541535*pow(nu,2))/1728. + 76*pow(chis,2)*pow(nu,2) + (13475*pow(nu,3))/144. + v*((236866403.0*chis)/169344. - (1136017*M_PI)/1176. + (236866403.0*chia*delta)/169344. + (17949971*chis*nu)/14112. - (110801*M_PI*nu)/63. + (7148033*chia*delta*nu)/3024. - (151637*chis*pow(nu,2))/168. - (7070*M_PI*pow(nu,2))/9. + (214655*chia*delta*pow(nu,2))/216. - (44065*chis*pow(nu,3))/54.)))))));
      Phi = Phi0-(1./(32*nu*pow(v,5)))*(1 + pow(v,2)*(3.685515873015873 + (55*nu)/12. + v*((565*chis)/24. - 10*M_PI + (565*chia*delta)/24. - (95*chis*nu)/6. + v*(41.03427047902494 + (83945*nu)/1008. + (1925*pow(nu,2))/48. + v*(v*(-152.29087883138126 - (6215*pow(chis,2))/48. + (730*chis*M_PI)/3. - 80*pow(M_PI,2) - (6215*chia*chis*delta)/24. + (730*chia*M_PI*delta)/3. - (6215*pow(chia,2)*pow(delta,2))/48. - (580858835.0*nu)/1.354752e6 + (685*pow(chis,2)*nu)/3. - (560*chis*M_PI*nu)/3. + (685*chia*chis*delta*nu)/3. - (2707675*pow(nu,2))/6912. - 95*pow(chis,2)*pow(nu,2) - (67375*pow(nu,3))/576. + v*((-1184332015.0*chis)/2.709504e6 + (5680085*M_PI)/18816. - (1184332015.0*chia*delta)/2.709504e6 - (89749855*chis*nu)/225792. + (554005*M_PI*nu)/1008. - (35740165*chia*delta*nu)/48384. + (758185*chis*pow(nu,2))/2688. + (17675*M_PI*pow(nu,2))/72. - (1073275*chia*delta*pow(nu,2))/3456. + (220325*chis*pow(nu,3))/864.)) - (413575*chis*log(v))/2016. + (4975*M_PI*log(v))/42. - (413575*chia*delta*log(v))/2016. - (220*chis*nu*log(v))/9. + (340*M_PI*nu*log(v))/3. - (6305*chia*delta*nu*log(v))/36. + (2405*chis*pow(nu,2)*log(v))/18.)))));
      break;
      
    case 4:
      t = t0-(5./(256.*nu*pow(v,8)))*(1 + pow(v,2)*(2.9484126984126986 + (11*nu)/3. + v*((226*chis)/15. - (32*M_PI)/5. + (226*chia*delta)/15. - (152*chis*nu)/15. + v*(6.020630590199042 - (81*pow(chia,2))/8. - (81*pow(chis,2))/8. - (81*chia*chis*delta)/4. + (5429*nu)/504. + 40*pow(chia,2)*nu + (pow(chis,2)*nu)/2. + (617*pow(nu,2))/72. + v*((82715*chis)/756. - (3980*M_PI)/63. + (82715*chia*delta)/756. + (352*chis*nu)/27. - (544*M_PI*nu)/9. + (2522*chia*delta*nu)/27. - (1924*chis*pow(nu,2))/27. + v*(88.28226004839215 - (20921*pow(chia,2))/224. + (6845*pow(chis,2))/672. - (584*chis*M_PI)/3. + 64*pow(M_PI,2) + (6845*chia*chis*delta)/336. - (584*chia*M_PI*delta)/3. + (1243*pow(chia,2)*pow(delta,2))/12. + (20062663*nu)/3.048192e6 + (3431*pow(chia,2)*nu)/12. - (43427*pow(chis,2)*nu)/168. + (448*chis*M_PI*nu)/3. - (2077*chia*chis*delta*nu)/6. - (434815*pow(nu,2))/4032. + (964*pow(chia,2)*pow(nu,2))/3. + (245*pow(chis,2)*pow(nu,2))/3. + (4435*pow(nu,3))/432. + v*((2523419515.0*chis)/1.524096e6 - (1067*pow(chia,2)*chis)/4. - (1067*pow(chis,3))/4. - (30400075*M_PI)/31752. + 228*pow(chia,2)*M_PI + 228*pow(chis,2)*M_PI + (2523419515.0*chia*delta)/1.524096e6 - (1067*pow(chia,3)*delta)/4. - (3201*chia*pow(chis,2)*delta)/4. + 456*chia*chis*M_PI*delta - (1067*pow(chia,2)*chis*pow(delta,2))/2. - (185447399.0*chis*nu)/381024. + (3806*pow(chia,2)*chis*nu)/3. + (751*pow(chis,3)*nu)/3. - (16999*M_PI*nu)/21. - 896*pow(chia,2)*M_PI*nu - 16*pow(chis,2)*M_PI*nu + (245309*chia*delta*nu)/336. + (3128*pow(chia,3)*delta*nu)/3. + (1429*chia*pow(chis,2)*delta*nu)/3. - (9131*chis*pow(nu,2))/168. - (2656*pow(chia,2)*chis*pow(nu,2))/3. - (56*pow(chis,3)*pow(nu,2))/3. - (4954*M_PI*pow(nu,2))/9. + (15349*chia*delta*pow(nu,2))/24. - (9781*chis*pow(nu,3))/18.)))))));
      Phi = Phi0-(1./(32*nu*pow(v,5)))*(1 + pow(v,2)*(3.685515873015873 + (55*nu)/12. + v*((565*chis)/24. - 10*M_PI + (565*chia*delta)/24. - (95*chis*nu)/6. + v*(15.051576475497606 - (405*pow(chia,2))/16. - (405*pow(chis,2))/16. - (405*chia*chis*delta)/8. + (27145*nu)/1008. + 100*pow(chia,2)*nu + (5*pow(chis,2)*nu)/4. + (3085*pow(nu,2))/144. + v*(v*(-110.35282506049019 + (104605*pow(chia,2))/896. - (34225*pow(chis,2))/2688. + (730*chis*M_PI)/3. - 80*pow(M_PI,2) - (34225*chia*chis*delta)/1344. + (730*chia*M_PI*delta)/3. - (6215*pow(chia,2)*pow(delta,2))/48. - (100313315.0*nu)/1.2192768e7 - (17155*pow(chia,2)*nu)/48. + (217135*pow(chis,2)*nu)/672. - (560*chis*M_PI*nu)/3. + (10385*chia*chis*delta*nu)/24. + (2174075*pow(nu,2))/16128. - (1205*pow(chia,2)*pow(nu,2))/3. - (1225*pow(chis,2)*pow(nu,2))/12. - (22175*pow(nu,3))/1728. + v*((-12617097575.0*chis)/2.4385536e7 + (5335*pow(chia,2)*chis)/64. + (5335*pow(chis,3))/64. + (152000375.0*M_PI)/508032. - (285*pow(chia,2)*M_PI)/4. - (285*pow(chis,2)*M_PI)/4. - (12617097575.0*chia*delta)/2.4385536e7 + (5335*pow(chia,3)*delta)/64. + (16005*chia*pow(chis,2)*delta)/64. - (285*chia*chis*M_PI*delta)/2. + (5335*pow(chia,2)*chis*pow(delta,2))/32. + (927236995.0*chis*nu)/6.096384e6 - (9515*pow(chia,2)*chis*nu)/24. - (3755*pow(chis,3)*nu)/48. + (84995*M_PI*nu)/336. + 280*pow(chia,2)*M_PI*nu + 5*pow(chis,2)*M_PI*nu - (1226545*chia*delta*nu)/5376. - (1955*pow(chia,3)*delta*nu)/6. - (7145*chia*pow(chis,2)*delta*nu)/48. + (45655*chis*pow(nu,2))/2688. + (830*pow(chia,2)*chis*pow(nu,2))/3. + (35*pow(chis,3)*pow(nu,2))/6. + (12385*M_PI*pow(nu,2))/72. - (76745*chia*delta*pow(nu,2))/384. + (48905*chis*pow(nu,3))/288.)) - (413575*chis*log(v))/2016. + (4975*M_PI*log(v))/42. - (413575*chia*delta*log(v))/2016. - (220*chis*nu*log(v))/9. + (340*M_PI*nu*log(v))/3. - (6305*chia*delta*nu*log(v))/36. + (2405*chis*pow(nu,2)*log(v))/18.)))));
      break;
      
    case 5:
      t = t0-(5./(256.*nu*pow(v,8)))*(1 + pow(v,2)*(2.9484126984126986 + (11*nu)/3. + v*((226*chis)/15. - (32*M_PI)/5. + (226*chia*delta)/15. - (152*chis*nu)/15. + v*(6.020630590199042 - (81*pow(chia,2))/8. - (81*pow(chis,2))/8. - (81*chia*chis*delta)/4. + (5429*nu)/504. + 40*pow(chia,2)*nu + (pow(chis,2)*nu)/2. + (617*pow(nu,2))/72. + v*((147101*chis)/756. + 6*pow(chia,2)*chis + 2*pow(chis,3) - (7729*M_PI)/252. + (147101*chia*delta)/756. + 2*pow(chia,3)*delta + 6*chia*pow(chis,2)*delta - (4906*chis*nu)/27. - 18*pow(chia,2)*chis*nu - 6*pow(chis,3)*nu + (13*M_PI*nu)/3. + (26*chia*delta*nu)/3. - 2*pow(chia,3)*delta*nu - 6*chia*pow(chis,2)*delta*nu - (68*chis*pow(nu,2))/3. + v*(88.28226004839215 - (20921*pow(chia,2))/224. + (6845*pow(chis,2))/672. - (584*chis*M_PI)/3. + 64*pow(M_PI,2) + (6845*chia*chis*delta)/336. - (584*chia*M_PI*delta)/3. + (1243*pow(chia,2)*pow(delta,2))/12. + (20062663*nu)/3.048192e6 + (3431*pow(chia,2)*nu)/12. - (43427*pow(chis,2)*nu)/168. + (448*chis*M_PI*nu)/3. - (2077*chia*chis*delta*nu)/6. - (434815*pow(nu,2))/4032. + (964*pow(chia,2)*pow(nu,2))/3. + (245*pow(chis,2)*pow(nu,2))/3. + (4435*pow(nu,3))/432. + v*((4074790483.0*chis)/1.524096e6 - (1121*pow(chia,2)*chis)/7. - (3237*pow(chis,3))/14. - (48249895*M_PI)/127008. + 228*pow(chia,2)*M_PI + 228*pow(chis,2)*M_PI + (4074790483.0*chia*delta)/1.524096e6 - (3237*pow(chia,3)*delta)/14. - (9711*chia*pow(chis,2)*delta)/14. + 456*chia*chis*M_PI*delta - (1067*pow(chia,2)*chis*pow(delta,2))/2. - (869712071.0*chis*nu)/381024. + (88271*pow(chia,2)*chis*nu)/84. + (14929*pow(chis,3)*nu)/84. + (50067*M_PI*nu)/56. - 896*pow(chia,2)*M_PI*nu - 16*pow(chis,2)*M_PI*nu + (30187*chia*delta*nu)/112. + (87455*pow(chia,3)*delta*nu)/84. + (39625*chia*pow(chis,2)*delta*nu)/84. - (2237903*chis*pow(nu,2))/1512. - (3574*pow(chia,2)*chis*pow(nu,2))/3. - (362*pow(chis,3)*pow(nu,2))/3. + (4957*M_PI*pow(nu,2))/9. - (115739*chia*delta*pow(nu,2))/216. - 34*pow(chia,3)*delta*pow(nu,2) - 102*chia*pow(chis,2)*delta*pow(nu,2) + (14341*chis*pow(nu,3))/54.)))))));
      Phi = Phi0-(1./(32*nu*pow(v,5)))*(1 + pow(v,2)*(3.685515873015873 + (55*nu)/12. + v*((565*chis)/24. - 10*M_PI + (565*chia*delta)/24. - (95*chis*nu)/6. + v*(15.051576475497606 - (405*pow(chia,2))/16. - (405*pow(chis,2))/16. - (405*chia*chis*delta)/8. + (27145*nu)/1008. + 100*pow(chia,2)*nu + (5*pow(chis,2)*nu)/4. + (3085*pow(nu,2))/144. + v*(v*(-110.35282506049019 + (104605*pow(chia,2))/896. - (34225*pow(chis,2))/2688. + (730*chis*M_PI)/3. - 80*pow(M_PI,2) - (34225*chia*chis*delta)/1344. + (730*chia*M_PI*delta)/3. - (6215*pow(chia,2)*pow(delta,2))/48. - (100313315.0*nu)/1.2192768e7 - (17155*pow(chia,2)*nu)/48. + (217135*pow(chis,2)*nu)/672. - (560*chis*M_PI*nu)/3. + (10385*chia*chis*delta*nu)/24. + (2174075*pow(nu,2))/16128. - (1205*pow(chia,2)*pow(nu,2))/3. - (1225*pow(chis,2)*pow(nu,2))/12. - (22175*pow(nu,3))/1728. + v*((-20373952415.0*chis)/2.4385536e7 + (5605*pow(chia,2)*chis)/112. + (16185*pow(chis,3))/224. + (241249475.0*M_PI)/2.032128e6 - (285*pow(chia,2)*M_PI)/4. - (285*pow(chis,2)*M_PI)/4. - (20373952415.0*chia*delta)/2.4385536e7 + (16185*pow(chia,3)*delta)/224. + (48555*chia*pow(chis,2)*delta)/224. - (285*chia*chis*M_PI*delta)/2. + (5335*pow(chia,2)*chis*pow(delta,2))/32. + (4348560355.0*chis*nu)/6.096384e6 - (441355*pow(chia,2)*chis*nu)/1344. - (74645*pow(chis,3)*nu)/1344. - (250335*M_PI*nu)/896. + 280*pow(chia,2)*M_PI*nu + 5*pow(chis,2)*M_PI*nu - (150935*chia*delta*nu)/1792. - (437275*pow(chia,3)*delta*nu)/1344. - (198125*chia*pow(chis,2)*delta*nu)/1344. + (11189515*chis*pow(nu,2))/24192. + (8935*pow(chia,2)*chis*pow(nu,2))/24. + (905*pow(chis,3)*pow(nu,2))/24. - (24785*M_PI*pow(nu,2))/144. + (578695*chia*delta*pow(nu,2))/3456. + (85*pow(chia,3)*delta*pow(nu,2))/8. + (255*chia*pow(chis,2)*delta*pow(nu,2))/8. - (71705*chis*pow(nu,3))/864.)) - (735505*chis*log(v))/2016. - (45*pow(chia,2)*chis*log(v))/4. - (15*pow(chis,3)*log(v))/4. + (38645*M_PI*log(v))/672. - (735505*chia*delta*log(v))/2016. - (15*pow(chia,3)*delta*log(v))/4. - (45*chia*pow(chis,2)*delta*log(v))/4. + (12265*chis*nu*log(v))/36. + (135*pow(chia,2)*chis*nu*log(v))/4. + (45*pow(chis,3)*nu*log(v))/4. - (65*M_PI*nu*log(v))/8. - (65*chia*delta*nu*log(v))/4. + (15*pow(chia,3)*delta*nu*log(v))/4. + (45*chia*pow(chis,2)*delta*nu*log(v))/4. + (85*chis*pow(nu,2)*log(v))/2.)))));
      break;
      
    case 6:
      t = t0-(5./(256.*nu*pow(v,8)))*(1 + pow(v,2)*(2.9484126984126986 + (11*nu)/3. + v*((226*chis)/15. - (32*M_PI)/5. + (226*chia*delta)/15. - (152*chis*nu)/15. + v*(6.020630590199042 - (81*pow(chia,2))/8. - (81*pow(chis,2))/8. - (81*chia*chis*delta)/4. + (5429*nu)/504. + 40*pow(chia,2)*nu + (pow(chis,2)*nu)/2. + (617*pow(nu,2))/72. + v*((147101*chis)/756. + 6*pow(chia,2)*chis + 2*pow(chis,3) - (7729*M_PI)/252. + (147101*chia*delta)/756. + 2*pow(chia,3)*delta + 6*chia*pow(chis,2)*delta - (4906*chis*nu)/27. - 18*pow(chia,2)*chis*nu - 6*pow(chis,3)*nu + (13*M_PI*nu)/3. + (26*chia*delta*nu)/3. - 2*pow(chia,3)*delta*nu - 6*chia*pow(chis,2)*delta*nu - (68*chis*pow(nu,2))/3. + v*(-428.291776175525 - (20921*pow(chia,2))/224. + (6845*pow(chis,2))/672. + (6848*EulerGamma)/105. - (584*chis*M_PI)/3. + (128*pow(M_PI,2))/3. + (6845*chia*chis*delta)/336. - (584*chia*M_PI*delta)/3. + (1243*pow(chia,2)*pow(delta,2))/12. + (3147553127.0*nu)/3.048192e6 + (3431*pow(chia,2)*nu)/12. - (43427*pow(chis,2)*nu)/168. + (448*chis*M_PI*nu)/3. - (451*pow(M_PI,2)*nu)/12. - (2077*chia*chis*delta*nu)/6. - (15211*pow(nu,2))/1728. + (964*pow(chia,2)*pow(nu,2))/3. + (245*pow(chis,2)*pow(nu,2))/3. + (25565*pow(nu,3))/1296. + v*((4074790483.0*chis)/1.524096e6 - (1121*pow(chia,2)*chis)/7. - (3237*pow(chis,3))/14. - (48249895*M_PI)/127008. + 228*pow(chia,2)*M_PI + 228*pow(chis,2)*M_PI + (4074790483.0*chia*delta)/1.524096e6 - (3237*pow(chia,3)*delta)/14. - (9711*chia*pow(chis,2)*delta)/14. + 456*chia*chis*M_PI*delta - (1067*pow(chia,2)*chis*pow(delta,2))/2. - (869712071.0*chis*nu)/381024. + (88271*pow(chia,2)*chis*nu)/84. + (14929*pow(chis,3)*nu)/84. + (50067*M_PI*nu)/56. - 896*pow(chia,2)*M_PI*nu - 16*pow(chis,2)*M_PI*nu + (30187*chia*delta*nu)/112. + (87455*pow(chia,3)*delta*nu)/84. + (39625*chia*pow(chis,2)*delta*nu)/84. - (2237903*chis*pow(nu,2))/1512. - (3574*pow(chia,2)*chis*pow(nu,2))/3. - (362*pow(chis,3)*pow(nu,2))/3. + (4957*M_PI*pow(nu,2))/9. - (115739*chia*delta*pow(nu,2))/216. - 34*pow(chia,3)*delta*pow(nu,2) - 102*chia*pow(chis,2)*delta*pow(nu,2) + (14341*chis*pow(nu,3))/54.) + (3424*log(16))/105. + (6848*log(v))/105.))))));
      Phi = Phi0-(1./(32*nu*pow(v,5)))*(1 + pow(v,2)*(3.685515873015873 + (55*nu)/12. + v*((565*chis)/24. - 10*M_PI + (565*chia*delta)/24. - (95*chis*nu)/6. + v*(15.051576475497606 - (405*pow(chia,2))/16. - (405*pow(chis,2))/16. - (405*chia*chis*delta)/8. + (27145*nu)/1008. + 100*pow(chia,2)*nu + (5*pow(chis,2)*nu)/4. + (3085*pow(nu,2))/144. + v*(v*(657.6504345051205 + (104605*pow(chia,2))/896. - (34225*pow(chis,2))/2688. - (1712*EulerGamma)/21. + (730*chis*M_PI)/3. - (160*pow(M_PI,2))/3. - (34225*chia*chis*delta)/1344. + (730*chia*M_PI*delta)/3. - (6215*pow(chia,2)*pow(delta,2))/48. - (15737765635.0*nu)/1.2192768e7 - (17155*pow(chia,2)*nu)/48. + (217135*pow(chis,2)*nu)/672. - (560*chis*M_PI*nu)/3. + (2255*pow(M_PI,2)*nu)/48. + (10385*chia*chis*delta*nu)/24. + (76055*pow(nu,2))/6912. - (1205*pow(chia,2)*pow(nu,2))/3. - (1225*pow(chis,2)*pow(nu,2))/12. - (127825*pow(nu,3))/5184. + v*((-20373952415.0*chis)/2.4385536e7 + (5605*pow(chia,2)*chis)/112. + (16185*pow(chis,3))/224. + (241249475.0*M_PI)/2.032128e6 - (285*pow(chia,2)*M_PI)/4. - (285*pow(chis,2)*M_PI)/4. - (20373952415.0*chia*delta)/2.4385536e7 + (16185*pow(chia,3)*delta)/224. + (48555*chia*pow(chis,2)*delta)/224. - (285*chia*chis*M_PI*delta)/2. + (5335*pow(chia,2)*chis*pow(delta,2))/32. + (4348560355.0*chis*nu)/6.096384e6 - (441355*pow(chia,2)*chis*nu)/1344. - (74645*pow(chis,3)*nu)/1344. - (250335*M_PI*nu)/896. + 280*pow(chia,2)*M_PI*nu + 5*pow(chis,2)*M_PI*nu - (150935*chia*delta*nu)/1792. - (437275*pow(chia,3)*delta*nu)/1344. - (198125*chia*pow(chis,2)*delta*nu)/1344. + (11189515*chis*pow(nu,2))/24192. + (8935*pow(chia,2)*chis*pow(nu,2))/24. + (905*pow(chis,3)*pow(nu,2))/24. - (24785*M_PI*pow(nu,2))/144. + (578695*chia*delta*pow(nu,2))/3456. + (85*pow(chia,3)*delta*pow(nu,2))/8. + (255*chia*pow(chis,2)*delta*pow(nu,2))/8. - (71705*chis*pow(nu,3))/864.) - (856*log(16))/21. - (1712*log(v))/21.) - (735505*chis*log(v))/2016. - (45*pow(chia,2)*chis*log(v))/4. - (15*pow(chis,3)*log(v))/4. + (38645*M_PI*log(v))/672. - (735505*chia*delta*log(v))/2016. - (15*pow(chia,3)*delta*log(v))/4. - (45*chia*pow(chis,2)*delta*log(v))/4. + (12265*chis*nu*log(v))/36. + (135*pow(chia,2)*chis*nu*log(v))/4. + (45*pow(chis,3)*nu*log(v))/4. - (65*M_PI*nu*log(v))/8. - (65*chia*delta*nu*log(v))/4. + (15*pow(chia,3)*delta*nu*log(v))/4. + (45*chia*pow(chis,2)*delta*nu*log(v))/4. + (85*chis*pow(nu,2)*log(v))/2.)))));
      break;
      
    case 7:
      t = t0-(5./(256.*nu*pow(v,8)))*(1 + pow(v,2)*(2.9484126984126986 + (11*nu)/3. + v*((226*chis)/15. - (32*M_PI)/5. + (226*chia*delta)/15. - (152*chis*nu)/15. + v*(6.020630590199042 - (81*pow(chia,2))/8. - (81*pow(chis,2))/8. - (81*chia*chis*delta)/4. + (5429*nu)/504. + 40*pow(chia,2)*nu + (pow(chis,2)*nu)/2. + (617*pow(nu,2))/72. + v*((147101*chis)/756. + 6*pow(chia,2)*chis + 2*pow(chis,3) - (7729*M_PI)/252. + (147101*chia*delta)/756. + 2*pow(chia,3)*delta + 6*chia*pow(chis,2)*delta - (4906*chis*nu)/27. - 18*pow(chia,2)*chis*nu - 6*pow(chis,3)*nu + (13*M_PI*nu)/3. + (26*chia*delta*nu)/3. - 2*pow(chia,3)*delta*nu - 6*chia*pow(chis,2)*delta*nu - (68*chis*pow(nu,2))/3. + v*(-428.291776175525 - (20921*pow(chia,2))/224. + (6845*pow(chis,2))/672. + (6848*EulerGamma)/105. - (584*chis*M_PI)/3. + (128*pow(M_PI,2))/3. + (6845*chia*chis*delta)/336. - (584*chia*M_PI*delta)/3. + (1243*pow(chia,2)*pow(delta,2))/12. + (3147553127.0*nu)/3.048192e6 + (3431*pow(chia,2)*nu)/12. - (43427*pow(chis,2)*nu)/168. + (448*chis*M_PI*nu)/3. - (451*pow(M_PI,2)*nu)/12. - (2077*chia*chis*delta*nu)/6. - (15211*pow(nu,2))/1728. + (964*pow(chia,2)*pow(nu,2))/3. + (245*pow(chis,2)*pow(nu,2))/3. + (25565*pow(nu,3))/1296. + v*((4074790483.0*chis)/1.524096e6 - (1121*pow(chia,2)*chis)/7. - (3237*pow(chis,3))/14. - (15419335*M_PI)/127008. + 228*pow(chia,2)*M_PI + 228*pow(chis,2)*M_PI + (4074790483.0*chia*delta)/1.524096e6 - (3237*pow(chia,3)*delta)/14. - (9711*chia*pow(chis,2)*delta)/14. + 456*chia*chis*M_PI*delta - (1067*pow(chia,2)*chis*pow(delta,2))/2. - (869712071.0*chis*nu)/381024. + (88271*pow(chia,2)*chis*nu)/84. + (14929*pow(chis,3)*nu)/84. - (75703*M_PI*nu)/756. - 896*pow(chia,2)*M_PI*nu - 16*pow(chis,2)*M_PI*nu + (30187*chia*delta*nu)/112. + (87455*pow(chia,3)*delta*nu)/84. + (39625*chia*pow(chis,2)*delta*nu)/84. - (2237903*chis*pow(nu,2))/1512. - (3574*pow(chia,2)*chis*pow(nu,2))/3. - (362*pow(chis,3)*pow(nu,2))/3. + (14809*M_PI*pow(nu,2))/378. - (115739*chia*delta*pow(nu,2))/216. - 34*pow(chia,3)*delta*pow(nu,2) - 102*chia*pow(chis,2)*delta*pow(nu,2) + (14341*chis*pow(nu,3))/54.) + (3424*log(16))/105. + (6848*log(v))/105.))))));
      Phi = Phi0-(1./(32*nu*pow(v,5)))*(1 + pow(v,2)*(3.685515873015873 + (55*nu)/12. + v*((565*chis)/24. - 10*M_PI + (565*chia*delta)/24. - (95*chis*nu)/6. + v*(15.051576475497606 - (405*pow(chia,2))/16. - (405*pow(chis,2))/16. - (405*chia*chis*delta)/8. + (27145*nu)/1008. + 100*pow(chia,2)*nu + (5*pow(chis,2)*nu)/4. + (3085*pow(nu,2))/144. + v*(v*(657.6504345051205 + (104605*pow(chia,2))/896. - (34225*pow(chis,2))/2688. - (1712*EulerGamma)/21. + (730*chis*M_PI)/3. - (160*pow(M_PI,2))/3. - (34225*chia*chis*delta)/1344. + (730*chia*M_PI*delta)/3. - (6215*pow(chia,2)*pow(delta,2))/48. - (15737765635.0*nu)/1.2192768e7 - (17155*pow(chia,2)*nu)/48. + (217135*pow(chis,2)*nu)/672. - (560*chis*M_PI*nu)/3. + (2255*pow(M_PI,2)*nu)/48. + (10385*chia*chis*delta*nu)/24. + (76055*pow(nu,2))/6912. - (1205*pow(chia,2)*pow(nu,2))/3. - (1225*pow(chis,2)*pow(nu,2))/12. - (127825*pow(nu,3))/5184. + v*((-20373952415.0*chis)/2.4385536e7 + (5605*pow(chia,2)*chis)/112. + (16185*pow(chis,3))/224. + (77096675*M_PI)/2.032128e6 - (285*pow(chia,2)*M_PI)/4. - (285*pow(chis,2)*M_PI)/4. - (20373952415.0*chia*delta)/2.4385536e7 + (16185*pow(chia,3)*delta)/224. + (48555*chia*pow(chis,2)*delta)/224. - (285*chia*chis*M_PI*delta)/2. + (5335*pow(chia,2)*chis*pow(delta,2))/32. + (4348560355.0*chis*nu)/6.096384e6 - (441355*pow(chia,2)*chis*nu)/1344. - (74645*pow(chis,3)*nu)/1344. + (378515*M_PI*nu)/12096. + 280*pow(chia,2)*M_PI*nu + 5*pow(chis,2)*M_PI*nu - (150935*chia*delta*nu)/1792. - (437275*pow(chia,3)*delta*nu)/1344. - (198125*chia*pow(chis,2)*delta*nu)/1344. + (11189515*chis*pow(nu,2))/24192. + (8935*pow(chia,2)*chis*pow(nu,2))/24. + (905*pow(chis,3)*pow(nu,2))/24. - (74045*M_PI*pow(nu,2))/6048. + (578695*chia*delta*pow(nu,2))/3456. + (85*pow(chia,3)*delta*pow(nu,2))/8. + (255*chia*pow(chis,2)*delta*pow(nu,2))/8. - (71705*chis*pow(nu,3))/864.) - (856*log(16))/21. - (1712*log(v))/21.) - (735505*chis*log(v))/2016. - (45*pow(chia,2)*chis*log(v))/4. - (15*pow(chis,3)*log(v))/4. + (38645*M_PI*log(v))/672. - (735505*chia*delta*log(v))/2016. - (15*pow(chia,3)*delta*log(v))/4. - (45*chia*pow(chis,2)*delta*log(v))/4. + (12265*chis*nu*log(v))/36. + (135*pow(chia,2)*chis*nu*log(v))/4. + (45*pow(chis,3)*nu*log(v))/4. - (65*M_PI*nu*log(v))/8. - (65*chia*delta*nu*log(v))/4. + (15*pow(chia,3)*delta*nu*log(v))/4. + (45*chia*pow(chis,2)*delta*nu*log(v))/4. + (85*chis*pow(nu,2)*log(v))/2.)))));
      break;
      
    default:
      cerr << "Somehow PNOrder=" << PNOrder << " didn't break from any switches..." << endl;
      exit(1);
    } // switch(int(2.0*PNPhaseOrder))
    
    return;
  }
};


void TaylorT2(const double delta, const double chis, const double chia, const double v0,
	      std::vector<double>& t, std::vector<double>& v, std::vector<double>& Phi,
	      const double PNPhaseOrder, const unsigned int NPoints)
{
  // Construct the TaylorT2 object
  T2 d(delta, chis, chia, PNPhaseOrder);
  
  // Set up the v vector
  unsigned int nroot;
  vector<double>xb1(20),xb2(20);
  zbrak(d,0.1,1.0,10000,xb1,xb2,nroot);
  double vMax=1.0;
  if(nroot>0) { vMax=rtbis(d,xb1[0],xb2[0],fabs(1.0-xb1[0])*1.e-8); }
  const double dv = (vMax-v0)/double(NPoints-1);
  v.resize(NPoints);
  for(unsigned int i=0; i<NPoints; ++i) { v[i] = v0+i*dv; }
  
  // Evaluate t and Phi for the chosen v
  d.tPhi(v, t, Phi);
  
  return;
}