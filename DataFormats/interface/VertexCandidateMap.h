#ifndef FLASHgg_VertexCandidateMap_h
#define FLASHgg_VertexCandidateMap_h

#include "DataFormats/Common/interface/Ptr.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"

namespace flashgg {
  //  typedef std::map<edm::Ptr<reco::Vertex>,edm::PtrVector<pat::PackedCandidate> > VertexCandidateMap;

  typedef std::pair<edm::Ptr<reco::Vertex>,edm::Ptr<pat::PackedCandidate> > VertexCandidatePair;
  typedef std::vector<VertexCandidatePair> VertexCandidateMap;
  
  struct compare_by_vtx {
    bool operator()(const VertexCandidatePair& left, const VertexCandidatePair& right) {
      return (left.first < right.first);
    }
  };

  struct compare_with_vtx {
    bool operator()(const VertexCandidatePair& left, const edm::Ptr<reco::Vertex>& right) {
      return (left.first < right);
    }
    bool operator()(const edm::Ptr<reco::Vertex>& left,const VertexCandidatePair& right) {
      return(left < right.first);
    }
  };

  struct compare_by_cand {
    bool operator()(const VertexCandidatePair& left, const VertexCandidatePair& right) {
      return (left.second < right.second);
    }
  };

  struct compare_with_cand {
    bool operator()(const VertexCandidatePair& left, const edm::Ptr<pat::PackedCandidate>& right) {
      return (left.second < right);
    }
    bool operator()(const edm::Ptr<pat::PackedCandidate>& left,const VertexCandidatePair& right) {
      return(left < right.second);
    }
  };


}

#endif
