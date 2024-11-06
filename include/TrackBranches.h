#ifndef TrackBranches_h
#define TrackBranches_h 1

#include "LCTupleConf.h" 

#include "CollectionBranches.h"


class TTree ;

namespace EVENT{
  class LCCollection ;
  class LCCEvent ;
}

/** TrackBranches holds branches created from a Track collection
 * 
 * @author F. Gaede, DESY
 * @version $Id$
 */

class TrackBranches : public CollectionBranches {
  
public:
  
  TrackBranches() {} ;

  // Following function is used to access parameters set in a steering file
  void writeTrkExtraParameters(bool setextraparameters){ _writeExtraParameters = setextraparameters; };
  
  virtual void initBranches( TTree* tree, const std::string& prefix="" ) ; //const char*  prefix=0) ;
  
  virtual void fill(const EVENT::LCCollection* col, EVENT::LCEvent* evt ) ;
  
  virtual ~TrackBranches() {} ;
  

private:
  
  bool _writeExtraParameters {} ;       /* Whether to write extra (2D) parameters */

  int   _ntrk  {} ;

  int   _trori[ LCT_TRACK_MAX ]  {} ;

  int   _trtyp[ LCT_TRACK_MAX ]  {} ;
  float _trch2[ LCT_TRACK_MAX ]  {} ;
  int   _trndf[ LCT_TRACK_MAX ]  {} ; 
  float _tredx[ LCT_TRACK_MAX ]  {} ;
  float _trede[ LCT_TRACK_MAX ]  {} ;
  float _trrih[ LCT_TRACK_MAX ]  {} ;
  int   _trthn[ LCT_TRACK_MAX ]  {} ;   // total number of hits
  int   _trnts[ LCT_TRACK_MAX ]  {} ;
  int   _trfts[ LCT_TRACK_MAX ]  {} ;
  int   _trsip[ LCT_TRACK_MAX ]  {} ;   // track stat atIP
  int   _trsfh[ LCT_TRACK_MAX ]  {} ;   // track stat atFirstHit
  int   _trslh[ LCT_TRACK_MAX ]  {} ;   // track stat atLastHit
  int   _trsca[ LCT_TRACK_MAX ]  {} ;   // track stat atCalorimeter

  int   _trtvhn[ LCT_TRACK_MAX ] {} ;   // total number of vertex hits
  int   _trtihn[ LCT_TRACK_MAX ] {} ;   // total number of inner hits
  int   _trtohn[ LCT_TRACK_MAX ] {} ;   // total number of outer hits
  int   _trtnh[ LCT_TRACK_MAX ]  {} ;   // total number of holes 
  float _trome[ LCT_TRACK_MAX ]  {} ;   // omega at IP state
  float _trtnl[ LCT_TRACK_MAX ]  {} ;   // tan lambda at IP state
  float _trthe[ LCT_TRACK_MAX ]  {} ;   // theta at IP state
  float _trdze[ LCT_TRACK_MAX ]  {} ;   // d0 at IP state
  float _trzze[ LCT_TRACK_MAX ]  {} ;   // z0 at IP state
  float _trphi[ LCT_TRACK_MAX ]  {} ;   // phi at IP state

  int   _ntrst  {} ;
  int   _tsloc[ LCT_TRACKSTATE_MAX ]  {} ; 
  float _tsdze[ LCT_TRACKSTATE_MAX ]  {} ;
  float _tsphi[ LCT_TRACKSTATE_MAX ]  {} ;
  float _tsome[ LCT_TRACKSTATE_MAX ]  {} ;
  float _tszze[ LCT_TRACKSTATE_MAX ]  {} ;
  float _tstnl[ LCT_TRACKSTATE_MAX ]  {} ;
  float _tsrpx[ LCT_TRACKSTATE_MAX ]  {} ;
  float _tsrpy[ LCT_TRACKSTATE_MAX ]  {} ;
  float _tsrpz[ LCT_TRACKSTATE_MAX ]  {} ;
  
  // extra (2D) parameters
  int   _trthi[ LCT_TRACK_MAX ][50]  {} ; // track hit indices     
  int   _trthd[ LCT_TRACK_MAX ][50]  {} ; // track hit subdetector 
  int   _trshn[ LCT_TRACK_MAX ][12]  {} ; // track hit per subdetector 
  float _trthx[ LCT_TRACK_MAX ][50]  {} ; // track hit x coord 
  float _trthy[ LCT_TRACK_MAX ][50]  {} ; // track hit y coord 
  float _trthz[ LCT_TRACK_MAX ][50]  {} ; // track hit z coord 
  float _tscov[ LCT_TRACKSTATE_MAX ] [15]  {} ; // covariance matrix 
  float _trcov[ LCT_TRACK_MAX ] [15]  {} ; // covariance matrix at IP state 

  // EVENT::TrackVec _tracks ;
  // EVENT::TrackerHitVec _hits ;
  
} ;

#endif



