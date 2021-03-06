#include "NumericalRecipes.hpp"

#include "WaveformAtAPoint.hpp"

#include "VectorFunctions.hpp"
#include "Interpolate.hpp"
#include "SWSHs.hpp"
#include "Utilities.hpp"

using namespace WaveformUtilities;
using namespace WaveformObjects;
using std::vector;
using std::setprecision;
using std::ios_base;
using std::endl;


WaveformAtAPoint::WaveformAtAPoint(const Waveform& W, const double dt, const double Vartheta, const double Varphi)
  : vartheta(Vartheta), varphi(Varphi)
{
  // Record that this is happening
  SetHistory(W.HistoryStr());
  History() << "### WaveformAtAPoint(W, " << setprecision(16) << dt << ", " << Vartheta << ", " << Varphi << ");" << endl;

  // Make sure to copy over some other data
  TypeIndexRef() = W.TypeIndex();
  TimeScaleRef() = W.TimeScale();

  // Set L,M data to something impossible, to denote that we're doing things at a point
  LMRef() = Matrix<int>(1, 2);
  LRef(0) = 0;
  MRef(0) = 0;

  // Construct a grid with even spacing dt whose size is the next power of 2
  const unsigned int N1 = (unsigned int)(floor((W.T().back()-W.T(0))/dt));
  const unsigned int N2 = (unsigned int)(pow(2.0,ceil(log2(N1))));
  vector<double> NewTime(N2);
  for(unsigned int i=0; i<N2; ++i) {
    NewTime[i] = W.T(0) + i*dt;
  }
  MagRef() = Matrix<double>(1, N2, 0.0);
  ArgRef() = Matrix<double>(1, N2, 0.0);

  // Step through the modes interpolating to the new time
  vector<double> SWSHAmp, SWSHPhi, Amplitude, Phase;
  SWSH(W.LM().RawData(), vartheta, varphi, SWSHAmp, SWSHPhi);
  for(unsigned int mode=0; mode<W.NModes(); ++mode) { // Loop over components
    Amplitude = SWSHAmp[mode] * WaveformUtilities::Interpolate(W.T(), W.Mag(mode), NewTime, 0.0);
    Phase     = SWSHPhi[mode] + WaveformUtilities::Interpolate(W.T(), W.Arg(mode), NewTime, W.Arg(mode).back());
    ReRef() += Amplitude * cos(Phase);
    ImRef() += Amplitude * sin(Phase);
  }
  TRef() = NewTime;
  if(W.R().size()==W.T().size()) {
    RRef() = WaveformUtilities::Interpolate(W.T(), W.R(), T());
  } else {
    RRef() = W.R();
  }
}

std::ostream& operator<<(std::ostream& os, const WaveformAtAPoint& a) {
  os << a.HistoryStr()
     << "# [1] = " << a.TimeScale() << endl
     << "# [2] = Re{" << a.Type() << "(" << a.Vartheta() << "," << a.Varphi() << ")}" << endl
     << "# [3] = Im{" << a.Type() << "(" << a.Vartheta() << "," << a.Vartheta() << ")}" << endl;
  for(unsigned int i=0; i<a.NTimes(); ++i) {
    os << a.T(i) << " " << a.Re(i) << " " << a.Im(i) << endl;
  }
  return os;
}
